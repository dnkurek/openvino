// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//
#include "slice_kernel_selector.h"

namespace kernel_selector {

slice_kernel_selector::slice_kernel_selector() { }

KernelsData slice_kernel_selector::GetBestKernels(const Params &params) const {
    return GetNaiveBestKernel(params, KernelType::SLICE);
}

} // namespace kernel_selector
