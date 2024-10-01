// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "normalize_kernel_selector.h"

namespace kernel_selector {
normalize_kernel_selector::normalize_kernel_selector() { }

KernelsData normalize_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::NORMALIZE);
}
}  // namespace kernel_selector
