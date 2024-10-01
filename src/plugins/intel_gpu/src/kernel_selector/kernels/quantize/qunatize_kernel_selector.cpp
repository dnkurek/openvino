// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "quantize_kernel_selector.h"

namespace kernel_selector {

quantize_kernel_selector::quantize_kernel_selector() { }

KernelsData quantize_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::QUANTIZE);
}
}  // namespace kernel_selector
