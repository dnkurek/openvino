// Copyright (C) 2023 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "permute_kernel_base.h"

namespace kernel_selector {

class PermuteKernel_f_y_axes : public PermuteKernelBase {
public:
    using Parent = PermuteKernelBase;
    using Parent::Parent;
    static PermuteKernel_f_y_axes& Instance() {
        static PermuteKernel_f_y_axes instance_;
        return instance_;
    }

    PermuteKernel_f_y_axes() : PermuteKernelBase("permute_f_y_axes") {}
    ~PermuteKernel_f_y_axes() override = default;

    bool Validate(const Params& p) const override;
    KernelsPriority GetKernelsPriority(const Params& params) const override;
    ParamsKey GetSupportedKey() const override;

protected:
    JitConstants GetJitConstants(const permute_params& params, const CommonDispatchData& dispatchData) const override;
    CommonDispatchData SetDefault(const permute_params& params) const override;
    std::vector<FusedOpType> GetSupportedFusedOps() const override {
        return {FusedOpType::ACTIVATION, FusedOpType::QUANTIZE, FusedOpType::ELTWISE};
    }
};
}  // namespace kernel_selector
