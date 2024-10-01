// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "detection_output_kernel_selector.h"

namespace kernel_selector {
experimental_detectron_detection_output_kernel_selector::experimental_detectron_detection_output_kernel_selector() { }

KernelsData experimental_detectron_detection_output_kernel_selector::GetBestKernels(
    const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::EXPERIMENTAL_DETECTRON_DETECTION_OUTPUT);
}
}  // namespace kernel_selector
