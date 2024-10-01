// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "reverse_kernel_selector.h"

namespace kernel_selector {

reverse_kernel_selector::reverse_kernel_selector() { }

KernelsData reverse_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::REVERSE);
}
}  // namespace kernel_selector
