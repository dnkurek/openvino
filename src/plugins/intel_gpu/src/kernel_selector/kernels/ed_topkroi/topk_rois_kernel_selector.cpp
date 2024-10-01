// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "topk_rois_kernel_selector.h"
#include "topk_rois_ref.h"

namespace kernel_selector {

experimental_detectron_topk_rois_kernel_selector::experimental_detectron_topk_rois_kernel_selector() { }

KernelsData experimental_detectron_topk_rois_kernel_selector::GetBestKernels(const Params &params) const {
    return GetNaiveBestKernel(params, KernelType::EXPERIMENTAL_DETECTRON_TOPK_ROIS);
}

} // namespace kernel_selector
