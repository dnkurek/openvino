// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "resample_kernel_ref.h"
#include "resample_kernel_opt.h"
#include "resample_kernel_onnx.h"
#include "resample_kernel_pil_ref.h"

namespace kernel_selector {
class resample_kernel_selector : public kernel_selector_base {
public:
    static resample_kernel_selector& Instance() {
        static resample_kernel_selector instance_;
        return instance_;
    }
    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &ResampleKernelRef::Instance(), &ResampleKernelOpt::Instance(), &ResampleKernelOnnx::Instance(), &ResampleKernelPilRef::Instance() };
	static struct ImplementationList impls = { list, 4 };

	return &impls;
    }

    resample_kernel_selector();

    virtual ~resample_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
