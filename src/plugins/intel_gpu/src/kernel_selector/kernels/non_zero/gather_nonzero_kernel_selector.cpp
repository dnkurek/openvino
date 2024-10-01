// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "gather_nonzero_kernel_selector.h"

namespace kernel_selector {

gather_nonzero_kernel_selector::gather_nonzero_kernel_selector() { }

KernelsData gather_nonzero_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::GATHER_NONZERO);
}
}  // namespace kernel_selector
