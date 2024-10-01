// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "concatenation_kernel_ref.h"
#include "concatenation_kernel_simple_ref.h"
#include "concatenation_kernel_depth_bfyx_no_pitch.h"
#include "concatenation_kernel_b_fs_yx_fsv16.h"
#include "concatenation_kernel_fs_b_yx_fsv32.h"

namespace kernel_selector {
class concatenation_kernel_selector : public kernel_selector_base {
public:
    static concatenation_kernel_selector& Instance() {
        static concatenation_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = {
		&ConcatenationKernelRef::Instance(),
		&ConcatenationKernel_simple_Ref::Instance(),
		&ConcatenationKernel_depth_bfyx_no_pitch::Instance(),
		&ConcatenationKernel_b_fs_yx_fsv16::Instance(),
		&ConcatenationKernel_fs_b_yx_fsv32::Instance()
	};
	static struct ImplementationList impls = { list, 5 };

	return &impls;
    }

    concatenation_kernel_selector();

    virtual ~concatenation_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
