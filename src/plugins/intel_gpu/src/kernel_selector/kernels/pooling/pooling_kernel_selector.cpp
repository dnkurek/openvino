// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "pooling_kernel_selector.h"

namespace kernel_selector {

pooling_kernel_selector::pooling_kernel_selector() { }

KernelsData pooling_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::POOLING);
}
}  // namespace kernel_selector
