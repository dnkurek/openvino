// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "embedding_bag_kernel_ref.h"

namespace kernel_selector {
class embedding_bag_kernel_selector : public kernel_selector_base {
public:
    static embedding_bag_kernel_selector& Instance() {
        static embedding_bag_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &EmbeddingBagKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    embedding_bag_kernel_selector();

    virtual ~embedding_bag_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
