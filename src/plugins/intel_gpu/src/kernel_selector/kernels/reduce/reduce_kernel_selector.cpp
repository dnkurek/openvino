// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "reduce_kernel_selector.h"

namespace kernel_selector {

reduce_kernel_selector::reduce_kernel_selector() { }

KernelsData reduce_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::REDUCE);
}
}  // namespace kernel_selector
