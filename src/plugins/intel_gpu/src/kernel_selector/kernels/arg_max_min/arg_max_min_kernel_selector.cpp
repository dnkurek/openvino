// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "arg_max_min_kernel_selector.h"
namespace kernel_selector {

arg_max_min_kernel_selector::arg_max_min_kernel_selector() {
}

KernelsData arg_max_min_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::ARG_MAX_MIN);
}
}  // namespace kernel_selector
