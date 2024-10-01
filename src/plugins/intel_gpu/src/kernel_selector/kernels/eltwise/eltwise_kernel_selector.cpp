// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "eltwise_kernel_selector.h"

namespace kernel_selector {
eltwise_kernel_selector::eltwise_kernel_selector() { }

KernelsData eltwise_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::ELTWISE);
}
}  // namespace kernel_selector
