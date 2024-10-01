// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "gather_nd_kernel_selector.h"

namespace kernel_selector {

gather_nd_kernel_selector::gather_nd_kernel_selector() { }

KernelsData gather_nd_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::GATHER_ND);
}
}  // namespace kernel_selector
