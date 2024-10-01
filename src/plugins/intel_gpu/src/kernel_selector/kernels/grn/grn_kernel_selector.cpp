// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "grn_kernel_selector.h"

namespace kernel_selector {
grn_kernel_selector::grn_kernel_selector() { }

KernelsData grn_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::GRN);
}
}  // namespace kernel_selector
