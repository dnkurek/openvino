// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "lrn_kernel_selector.h"

namespace kernel_selector {
lrn_kernel_selector::lrn_kernel_selector() { }

KernelsData lrn_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::LRN);
}
}  // namespace kernel_selector
