// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "concatenation_kernel_selector.h"

namespace kernel_selector {
concatenation_kernel_selector::concatenation_kernel_selector() { }

KernelsData concatenation_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::CONCATENATION);
}
}  // namespace kernel_selector
