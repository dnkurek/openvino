// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "mvn_kernel_selector.h"

namespace kernel_selector {
mvn_kernel_selector::mvn_kernel_selector() { }

KernelsData mvn_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::MVN);
}
}  // namespace kernel_selector
