// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "range_kernel_selector.h"

namespace kernel_selector {

range_kernel_selector::range_kernel_selector() { }

KernelsData range_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::RANGE);
}
}  // namespace kernel_selector
