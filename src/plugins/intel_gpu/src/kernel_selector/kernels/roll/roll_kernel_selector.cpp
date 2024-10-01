// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "roll_kernel_selector.hpp"

namespace kernel_selector {

roll_kernel_selector::roll_kernel_selector() { }

KernelsData roll_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::ROLL);
}

}  // namespace kernel_selector
