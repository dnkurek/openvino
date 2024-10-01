// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "permute_kernel_selector.h"

namespace kernel_selector {

permute_kernel_selector::permute_kernel_selector() { }

KernelsData permute_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::PERMUTE);
}
}  // namespace kernel_selector
