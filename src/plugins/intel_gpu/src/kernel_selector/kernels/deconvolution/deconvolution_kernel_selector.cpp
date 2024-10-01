// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "deconvolution_kernel_selector.h"

namespace kernel_selector {
deconvolution_kernel_selector::deconvolution_kernel_selector() { }

KernelsData deconvolution_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::DECONVOLUTION);
}
}  // namespace kernel_selector
