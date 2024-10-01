// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "grid_sample_kernel_selector.hpp"

namespace kernel_selector {

grid_sample_kernel_selector::grid_sample_kernel_selector() { }

KernelsData grid_sample_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::GRID_SAMPLE);
}

}  // namespace kernel_selector
