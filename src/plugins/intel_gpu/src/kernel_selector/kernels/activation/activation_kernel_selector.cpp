// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "activation_kernel_selector.h"

namespace kernel_selector {
activation_kernel_selector::activation_kernel_selector() {
}

KernelsData activation_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::ACTIVATION);
}
}  // namespace kernel_selector
