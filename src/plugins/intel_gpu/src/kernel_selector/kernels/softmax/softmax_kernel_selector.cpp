﻿// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "softmax_kernel_selector.h"

namespace kernel_selector {

softmax_kernel_selector::softmax_kernel_selector() { }

KernelsData softmax_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::SOFT_MAX);
}
}  // namespace kernel_selector
