// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "deconvolution_kernel_ref.h"
#include "deconvolution_kernel_bfyx_opt.h"
#include "deconvolution_kernel_b_fs_zyx_fsv16.h"
#include "deconvolution_kernel_b_fs_zyx_fsv16_dw.h"
#include "deconvolution_kernel_imad_ref.hpp"
#include "deconvolution_kernel_imad_along_f_tile_bfx.hpp"

namespace kernel_selector {
class deconvolution_kernel_selector : public kernel_selector_base {
public:
    static deconvolution_kernel_selector& Instance() {
        static deconvolution_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = {
		&DeconvolutionKernelRef::Instance(),
		&DeconvolutionKernel_bfyx_opt::Instance(),
		&DeconvolutionKernel_b_fs_zyx_fsv16::Instance(),
		&DeconvolutionKernel_b_fs_zyx_fsv16_dw::Instance(),
		&DeconvolutionKernel_imad_ref::Instance(),
		&DeconvolutionKernel_imad_along_f_tile_bfx::Instance()
	};
	static struct ImplementationList impls = { list, 6 };

	return &impls;
    }

    deconvolution_kernel_selector();

    virtual ~deconvolution_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
