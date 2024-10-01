// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "broadcast_kernel_selector.h"

namespace kernel_selector {
broadcast_kernel_selector::broadcast_kernel_selector() { }

KernelsData broadcast_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::BROADCAST);
}
}  // namespace kernel_selector
