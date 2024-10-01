// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "reorder_weights_kernel_selector.h"

namespace kernel_selector {

ReorderWeightsKernelSelector::ReorderWeightsKernelSelector() {
}

KernelsData ReorderWeightsKernelSelector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::REORDER);
}
}  // namespace kernel_selector
