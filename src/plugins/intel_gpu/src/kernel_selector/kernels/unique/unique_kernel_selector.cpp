// Copyright (C) 2023 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "unique_kernel_selector.hpp"

namespace kernel_selector {

unique_count_kernel_selector::unique_count_kernel_selector() { }

KernelsData unique_count_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::UNIQUE_COUNT);
}

unique_gather_kernel_selector::unique_gather_kernel_selector() { }

KernelsData unique_gather_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::UNIQUE_GATHER);
}

}  // namespace kernel_selector
