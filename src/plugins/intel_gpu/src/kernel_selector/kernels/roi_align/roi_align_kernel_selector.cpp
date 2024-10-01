// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//
#include "roi_align_kernel_selector.h"

namespace kernel_selector {

roi_align_kernel_selector::roi_align_kernel_selector() { }

KernelsData roi_align_kernel_selector::GetBestKernels(const Params &params) const {
    return GetNaiveBestKernel(params, KernelType::ROI_ALIGN);
}

} // namespace kernel_selector
