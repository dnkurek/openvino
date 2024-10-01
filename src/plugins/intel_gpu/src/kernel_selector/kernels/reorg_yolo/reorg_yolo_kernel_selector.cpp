// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "reorg_yolo_kernel_selector.h"

namespace kernel_selector {

reorg_yolo_kernel_selector::reorg_yolo_kernel_selector() { }

KernelsData reorg_yolo_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::REORG_YOLO);
}
}  // namespace kernel_selector
