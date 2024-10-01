// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "eltwise_kernel_ref.h"
#include "eltwise_kernel_vload8.h"
#include "eltwise_kernel_mixed_byxf_and_fs_b_yx_fsv32.h"
#include "eltwise_kernel_fs_b_yx_fsv32.h"
#include "eltwise_kernel_blocked_opt.h"

namespace kernel_selector {
class eltwise_kernel_selector : public kernel_selector_base {
public:
    static eltwise_kernel_selector& Instance() {
        static eltwise_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = {
		&EltwiseKernelRef::Instance(),
		&EltwiseKernel_mixed_byxf_and_fs_b_yx_fsv32::Instance(),
		&EltwiseKernel_blocked_opt::Instance(),
		&EltwiseKernel_fs_b_yx_fsv32::Instance(),
		&EltwiseKernel_vload8::Instance()
	};
	static struct ImplementationList impls = { list, 5 };

	return &impls;
    }

    eltwise_kernel_selector();

    virtual ~eltwise_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
