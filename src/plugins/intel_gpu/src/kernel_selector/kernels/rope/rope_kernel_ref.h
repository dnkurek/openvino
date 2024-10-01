// Copyright (C) 2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "rope_kernel_base.h"

namespace kernel_selector {
class RoPEKernelRef : public RoPEKernelBase {
public:
    using Parent = RoPEKernelBase;
    static RoPEKernelRef& Instance() {
        static RoPEKernelRef instance_;
        return instance_;
    }

    RoPEKernelRef() : RoPEKernelBase("rope_ref") {}
    virtual ~RoPEKernelRef() {}

    KernelsData GetKernelsData(const Params& params) const override;
    KernelsPriority GetKernelsPriority(const Params& params) const override;
    ParamsKey GetSupportedKey() const override;
};
}  // namespace kernel_selector
