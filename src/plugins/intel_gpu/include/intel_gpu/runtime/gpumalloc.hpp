// Copyright (C) 2018-2025 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "layout.hpp"
#include "memory_caps.hpp"
#include "utils.hpp"

#include <vector>

namespace cldnn {

class gpuMalloc;

struct allocEntry {
	memory_ptr ptr;
	size_t size;
	size_t offset;
};

struct allocChunk {
	memory_ptr base;
	size_t size;
	std::vector<std::shared_ptr<allocEntry>> entries;
};

struct allocGap {
	std::shared_ptr<allocChunk> chunk;
	uint64_t size;
	uint64_t offset;
};

struct gpuMallocMemPtr {
    gpuMalloc *_myMalloc;
    memory_ptr _base;
    memory_ptr _ptr;
};

class gpuMalloc {
    engine& _engine;
    size_t _blockSize;
    size_t _alignment;

    std::vector<std::shared_ptr<allocChunk>> chunks;

    std::shared_ptr<allocGap> getChunkSmallestFeasibleGap(std::shared_ptr<allocChunk> chunk, uint64_t size);
    std::shared_ptr<allocEntry> allocateGap(std::shared_ptr<allocGap> gap, layout layout);
    std::shared_ptr<allocChunk> createChunk(uint64_t size);

public:
    explicit gpuMalloc(engine& engine, size_t blockSize, size_t alignment);
    ~gpuMalloc();

    std::shared_ptr<gpuMallocMemPtr> malloc(const layout layout);
    void free(gpuMallocMemPtr ptr);
};

}  // namespace cldnn
