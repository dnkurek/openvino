// Copyright (C) 2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "swiglu_kernel_base.h"

namespace kernel_selector {
class SwiGLUKernelRef : public SwiGLUKernelBase {
public:
    static SwiGLUKernelRef& Instance() {
        static SwiGLUKernelRef instance_;
        return instance_;
    }

    SwiGLUKernelRef() : SwiGLUKernelBase("swiglu_gpu_ref") {}
    virtual ~SwiGLUKernelRef() {}

protected:
    KernelsPriority GetKernelsPriority(const Params& params) const override;
    ParamsKey GetSupportedKey() const override;
};
}  // namespace kernel_selector
