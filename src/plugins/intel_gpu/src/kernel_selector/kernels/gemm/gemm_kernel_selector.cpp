// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "gemm_kernel_selector.h"

namespace kernel_selector {
gemm_kernel_selector::gemm_kernel_selector() { }

KernelsData gemm_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::GEMM);
}
}  // namespace kernel_selector
