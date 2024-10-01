// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "reorder_kernel.h"
#include "reorder_kernel_fast_b1.h"
#include "reorder_from_winograd_2x3_kernel.h"
#include "reorder_to_winograd_2x3_kernel.h"
#include "reorder_kernel_to_yxfb_batched.h"
#include "reorder_biplanar_nv12.h"
#include "reorder_kernel_fs_b_yx_fsv32_to_bfyx.h"
#include "reorder_kernel_bfyx_to_blocked_format.h"
#include "reorder_kernel_b_fs_yx_fsv16_fsv32_to_bfyx.h"

namespace kernel_selector {
class reorder_kernel_selector : public kernel_selector_base {
public:
    static reorder_kernel_selector& Instance() {
        static reorder_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = {
		&ReorderKernelRef::Instance(),
		&ReorderKernelFastBatch1::Instance(),
		&ReorderFromWinograd2x3Kernel::Instance(),
		&ReorderKernel_to_yxfb_batched::Instance(),
		&reorder_biplanar_nv12::Instance(),
		&ReorderKernel_fs_b_yx_fsv32_to_bfyx::Instance(),
		&ReorderKernel_bfyx_to_blocked_format::Instance(),
		&ReorderKernel_b_fs_yx_fsv16_fsv32_to_bfyx::Instance()
	};
	static struct ImplementationList impls = { list, 9 };

	return &impls;
    }

    reorder_kernel_selector();

    ~reorder_kernel_selector();

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
