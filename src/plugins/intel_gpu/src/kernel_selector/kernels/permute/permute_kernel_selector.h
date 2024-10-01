// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "permute_kernel_ref.h"
#include "permute_kernel_tile_8x8_4x4.h"
#include "permute_kernel_tile_8x8_4x4_fsv.h"
#include "permute_kernel_bfzyx_to_bfyxz.h"
#include "permute_kernel_f_y_axes.h"

namespace kernel_selector {
class permute_kernel_selector : public kernel_selector_base {
public:
    static permute_kernel_selector& Instance() {
        static permute_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = {
		&PermuteKernelRef::Instance(),
		&PermuteKernel_tile_8x8_4x4::Instance(),
		&PermuteKernel_tile_8x8_4x4_fsv::Instance(),
		&PermuteKernel_bfzyx_to_bfyxz::Instance(),
		&PermuteKernel_f_y_axes::Instance()
	};
	static struct ImplementationList impls = { list, 5 };

	return &impls;
    }

    permute_kernel_selector();

    virtual ~permute_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
