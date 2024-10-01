// Copyright (C) 2023 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "rms_kernel_selector.h"

namespace kernel_selector {
rms_kernel_selector::rms_kernel_selector() { }

KernelsData rms_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::RMS);
}
}  // namespace kernel_selector
