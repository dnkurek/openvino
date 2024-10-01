// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "multiclass_nms_kernel_selector.h"

namespace kernel_selector {
multiclass_nms_kernel_selector::multiclass_nms_kernel_selector() { }

KernelsData multiclass_nms_kernel_selector::GetBestKernels(
    const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::MULTICLASS_NMS);
}
}  // namespace kernel_selector
