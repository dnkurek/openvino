// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "reorder_kernel_base.h"

namespace kernel_selector {
class ReorderWeightsKernel : public ReorderKernelBase {
public:
    static ReorderWeightsKernel& Instance() {
        static ReorderWeightsKernel instance_;
        return instance_;
    }

    ReorderWeightsKernel() : ReorderKernelBase("reorder_weights") {}
    virtual ~ReorderWeightsKernel() {}
    JitConstants GetJitConstants(const reorder_weights_params& params) const override;
    KernelsData GetKernelsData(const Params& params) const override;
    KernelsPriority GetKernelsPriority(const Params& params) const override;
    ParamsKey GetSupportedKey() const override;
};
}  // namespace kernel_selector
