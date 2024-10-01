// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "gemm_kernel_ref.h"
#include "gemm_kernel_tiled_opt.h"
#include "gemm_kernel_mmad_int8.h"
#include "gemm_kernel_mmad_int8_slm.h"

namespace kernel_selector {
class gemm_kernel_selector : public kernel_selector_base {
public:
    static gemm_kernel_selector& Instance() {
        static gemm_kernel_selector instance;
        return instance;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = {
		&GemmKernelRef::Instance(),
		&GemmKernelTiledOpt::Instance(),
		&GemmKernelMMADint8::Instance(),
		&GemmKernelMMADslmInt8::Instance()
	};
	static struct ImplementationList impls = { list, 4 };

	return &impls;
    }

    gemm_kernel_selector();
    virtual ~gemm_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
