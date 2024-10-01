// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "pooling_kernel_gpu_ref.h"
#include "pooling_kernel_gpu_byxf_opt.h"
#include "pooling_kernel_gpu_bfyx_block_opt.h"
#include "pooling_kernel_gpu_byxf_padding_opt.h"
#include "pooling_kernel_gpu_int8_ref.h"
#include "pooling_kernel_gpu_b_fs_yx_fsv4.h"
#include "pooling_kernel_gpu_fs_b_yx_fsv32.h"
#include "pooling_kernel_gpu_b_fs_yx_fsv16.h"
#include "pooling_kernel_gpu_bsv16_fsv16.h"
#include "pooling_kernel_gpu_b_fs_zyx_fsv16_imad.h"
#include "pooling_kernel_gpu_bs_fs_yx_bsv16_fsv16.h"

namespace kernel_selector {
class pooling_kernel_selector : public kernel_selector_base {
public:
    static pooling_kernel_selector& Instance() {
        static pooling_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = {
		&PoolingKernelGPURef::Instance(),
		&PoolingKernelGPUByxfOpt::Instance(),
		&PoolingKernelGPUBfyxBlockOpt::Instance(),
		&PoolingKernelGPUByxfPaddingOpt::Instance(),
		&PoolingKernelGPUInt8Ref::Instance(),
		&PoolingKerneGPU_b_fs_yx_fsv4::Instance(),
		&PoolingKerneGPU_fs_b_yx_fsv32::Instance(),
		&PoolingKernel_b_fs_yx_fsv16::Instance(),
		&PoolingKernel_bsv16_fsv16::Instance(),
		&PoolingKernelGPU_b_fs_zyx_fsv16_imad::Instance(),
		&Pooling_kernel_gpu_bs_fs_yx_bsv_16_fsv16::Instance()
	};
	static struct ImplementationList impls = { list, 11 };

	return &impls;
    }


    pooling_kernel_selector();

    virtual ~pooling_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
