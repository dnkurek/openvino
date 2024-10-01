// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "resample_kernel_selector.h"

namespace kernel_selector {
resample_kernel_selector::resample_kernel_selector() { }

KernelsData resample_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::RESAMPLE);
}
}  // namespace kernel_selector
