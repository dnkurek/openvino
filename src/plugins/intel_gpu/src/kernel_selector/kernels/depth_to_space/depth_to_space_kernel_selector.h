// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "depth_to_space_kernel_ref.h"
#include "depth_to_space_kernel_block2_opt.h"

namespace kernel_selector {
class depth_to_space_kernel_selector : public kernel_selector_base {
public:
    static depth_to_space_kernel_selector& Instance() {
        static depth_to_space_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &DepthToSpaceKernelRef::Instance(), &DepthToSpaceKernelBlock2Opt::Instance() };
	static struct ImplementationList impls = { list, 2 };

	return &impls;
    }

    depth_to_space_kernel_selector();

    virtual ~depth_to_space_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
