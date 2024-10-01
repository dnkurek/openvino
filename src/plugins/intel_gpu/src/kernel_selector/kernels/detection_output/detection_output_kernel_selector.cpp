// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "detection_output_kernel_selector.h"

namespace kernel_selector {
detection_output_kernel_selector::detection_output_kernel_selector() { }

KernelsData detection_output_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::DETECTION_OUTPUT);
}
}  // namespace kernel_selector
