// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "mvn_kernel_ref.h"
#include "mvn_kernel_bfyx_opt.h"
#include "mvn_kernel_b_fs_yx_fsv16_imad.hpp"
#include "mvn_kernel_bs_fs_yx_bsv32.hpp"

namespace kernel_selector {
class mvn_kernel_selector : public kernel_selector_base {
public:
    static mvn_kernel_selector& Instance() {
        static mvn_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = {
		&MVNKernelRef::Instance(),
		&MVNKernelBfyxOpt::Instance(),
		&MVNKernel_b_fs_yx_fsv16_imad::Instance(),
		&MVNKernel_bs_fs_yx_bsv32::Instance()
	};
	static struct ImplementationList impls = { list, 4 };

	return &impls;
    }

    mvn_kernel_selector();

    virtual ~mvn_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
