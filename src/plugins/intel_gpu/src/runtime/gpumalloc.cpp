// Copyright (C) 2018-2025 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include <algorithm>
#include <fstream>
#include <vector>

#include "intel_gpu/runtime/memory.hpp"
#include "intel_gpu/runtime/engine.hpp"
#include "intel_gpu/runtime/gpumalloc.hpp"

namespace cldnn {

gpuMalloc::gpuMalloc(engine& engine, size_t blockSize, size_t alignment) :
	_engine(engine), _blockSize(blockSize), _alignment(alignment) {
}

gpuMalloc::~gpuMalloc() {
	std::cout << "FREE" << std::endl;
}

std::shared_ptr<allocGap> gpuMalloc::getChunkSmallestFeasibleGap(std::shared_ptr<allocChunk> chunk, uint64_t size) {
	/* Size needs to be aligned aswell */
	size = align_to(size, _alignment);

	/* Initialize gap data structure to biggest possible */
	//std::shared_ptr<allocGap> allocGap = std::make_shared<allocGap>();
	auto allocGap = std::make_shared<struct allocGap>();
	allocGap->chunk = chunk;
	allocGap->size = _blockSize + 1;
	allocGap->offset = 0;

	std::vector<std::shared_ptr<allocEntry>> *entries = &chunk->entries;

	for (auto& entry : *entries) {
		uint64_t entryEnd = entry->offset + entry->size;

		uint64_t search = chunk->size - entryEnd;

		/* Compare the end of this entry with the beginnings of other entries */
		for (auto& cmpEntry : *entries) {
			uint64_t distance = cmpEntry->offset - entryEnd;
			if(distance < search) {
				search = distance;
			}
		}

		/* No fit */
		if (size > search) {
			continue;
		}

		/* Perfect fit */
		if(search == size) {
			allocGap->size = search;
			allocGap->offset = entryEnd;
			return allocGap;
		}

		/* Better fit */
		if(search < allocGap->size) {
			allocGap->size = search;
			allocGap->offset = entryEnd;
		}
	}

	return allocGap;
}

std::shared_ptr<allocEntry> gpuMalloc::allocateGap(std::shared_ptr<allocGap> gap, layout _layout) {
	//std::vector<allocEntry> *entries = &gap.chunk->entries;
	uint64_t size = gap->size;
	uint64_t offset = gap->offset;

	std::shared_ptr<allocEntry> entry = std::make_shared<allocEntry>();

	entry->ptr = _engine.create_subbuffer(*gap->chunk->base, _layout, offset);
	//entry->ptr = _engine.reinterpret_buffer(*gap->chunk->base, _layout);
	entry->size = size;
	entry->offset = offset;

	gap->chunk->entries.push_back(entry);


	return entry;
}

std::shared_ptr<allocChunk> gpuMalloc::createChunk(uint64_t size) {
	std::shared_ptr<allocChunk> chunk = std::make_shared<allocChunk>();

	size = align_to(size, _blockSize);

	chunk->base = _engine.allocate_memory(layout{{static_cast<long int>(size)}, data_types::i8, format::bfyx}, false);
	chunk->size = size;

	chunks.push_back(chunk);

	return chunk;
}

std::shared_ptr<gpuMallocMemPtr> gpuMalloc::malloc(const layout _layout) {
	uint64_t size = _layout.bytes_count();


	/* Use a best-match approach, because these are not allocated very often */
	/* But efficient memory usage here is very important */

	std::shared_ptr<struct gpuMallocMemPtr> ret = std::make_shared<struct gpuMallocMemPtr>();
	//struct gpuMallocMemPtr ret;

	/* Point to ourselves so memory can be freed later on destructor */
	//ret->_myMalloc = this;
	ret->_ptr = nullptr;

	auto bestGap = std::make_shared<struct allocGap>();
	//struct allocGap bestGap;
	bestGap->chunk = nullptr;
	bestGap->size = _blockSize + 1;
	bestGap->offset = 0;

	// Find every gap in each memory chunk

	for (auto chunk : chunks) {
		auto candidateGap = getChunkSmallestFeasibleGap(chunk, size);

		if(candidateGap->size < bestGap->size) {
			bestGap->chunk = chunk;
			bestGap->size = candidateGap->size;
			bestGap->offset = candidateGap->offset;
		}
	}

	// Gap was not found
	if (bestGap->chunk == nullptr) {
		uint64_t newSize = align_to(size, _blockSize);
		auto chunk = createChunk(newSize);
		bestGap->chunk = chunks[chunks.size() - 1];
		bestGap->size = size;
		bestGap->offset = 0;
	}

	bestGap->size = align_to(size, _alignment);

	auto entry = allocateGap(bestGap, _layout);
	ret->_ptr = entry->ptr;
	//ret->_ptr = memr;
	//ret->_ptr = neww; 
	//ret->_ptr = bestGap->chunk->base;
	//
	std::cout << "MALLOC" << std::endl;

	return ret;
}

void gpuMalloc::free(gpuMallocMemPtr ptr) {
	std::cout << "FREE" << std::endl;
}

}  // namespace cldnn
