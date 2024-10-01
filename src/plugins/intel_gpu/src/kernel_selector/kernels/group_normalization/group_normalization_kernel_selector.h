// Copyright (C) 2023 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//
#pragma once
#include "kernel_selector.h"
#include "group_normalization_kernel_ref.h"
#include "group_normalization_kernel_bfyx_opt.h"
#include "group_normalization_kernel_b_fs_yx_fsv16.h"

namespace kernel_selector {
class group_normalization_kernel_selector : public kernel_selector_base {
public:
    static group_normalization_kernel_selector& Instance() {
        static group_normalization_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = {
		&GroupNormalizationKernelRef::Instance(),
		&GroupNormalizationKernelBfyx::Instance(),
		&GroupNormalizationKernel_b_fs_yx_fsv16::Instance()
	};
	static struct ImplementationList impls = { list, 3 };

	return &impls;
    }

    group_normalization_kernel_selector();

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
