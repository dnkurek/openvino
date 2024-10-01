// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "roi_pooling_kernel_selector.h"

namespace kernel_selector {
roi_pooling_kernel_selector::roi_pooling_kernel_selector() { }

KernelsData roi_pooling_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::ROI_POOLING);
}
}  // namespace kernel_selector
