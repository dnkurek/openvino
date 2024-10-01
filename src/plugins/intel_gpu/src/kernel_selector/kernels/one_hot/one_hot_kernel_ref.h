// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "one_hot_kernel_base.h"

namespace kernel_selector {
class OneHotKernelRef : public OneHotKernelBase {
public:
    static OneHotKernelRef& Instance() {
        static OneHotKernelRef instance_;
        return instance_;
    }

    OneHotKernelRef() : OneHotKernelBase("one_hot_ref") {}

    KernelsData GetKernelsData(const Params& params) const override;
    KernelsPriority GetKernelsPriority(const Params& params) const override;
    ParamsKey GetSupportedKey() const override;
};
}  // namespace kernel_selector
