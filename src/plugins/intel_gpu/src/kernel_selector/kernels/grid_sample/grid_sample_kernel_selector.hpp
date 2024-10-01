// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "grid_sample_kernel_ref.hpp"

namespace kernel_selector {

/*
 * GridSample kernel selector.
 */
class grid_sample_kernel_selector : public kernel_selector_base {
public:
    static grid_sample_kernel_selector& Instance() {
        static grid_sample_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &GridSampleKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    grid_sample_kernel_selector();
    KernelsData GetBestKernels(const Params& params) const override;
};

}  // namespace kernel_selector
