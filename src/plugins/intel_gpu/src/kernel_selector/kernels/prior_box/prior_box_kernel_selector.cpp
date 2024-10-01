// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "prior_box_kernel_selector.h"

namespace kernel_selector {
KernelsData kernel_selector::prior_box_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::PRIOR_BOX);
}

prior_box_kernel_selector::prior_box_kernel_selector() { }
}  // namespace kernel_selector
