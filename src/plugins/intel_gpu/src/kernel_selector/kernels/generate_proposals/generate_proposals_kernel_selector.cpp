// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "generate_proposals_kernel_selector.h"

namespace kernel_selector {
generate_proposals_kernel_selector::generate_proposals_kernel_selector() { }

KernelsData generate_proposals_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::GENERATE_PROPOSALS);
}
}  // namespace kernel_selector
