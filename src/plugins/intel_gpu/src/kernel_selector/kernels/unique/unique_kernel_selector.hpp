// Copyright (C) 2023 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "unique_kernel_ref.hpp"

namespace kernel_selector {

class unique_count_kernel_selector : public kernel_selector_base {
public:
    static unique_count_kernel_selector& Instance() {
        static unique_count_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &UniqueCountKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    unique_count_kernel_selector();
    KernelsData GetBestKernels(const Params& params) const override;
};

class unique_gather_kernel_selector : public kernel_selector_base {
public:
    static unique_gather_kernel_selector& Instance() {
        static unique_gather_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &UniqueGatherKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    unique_gather_kernel_selector();
    KernelsData GetBestKernels(const Params& params) const override;
};

}  // namespace kernel_selector
