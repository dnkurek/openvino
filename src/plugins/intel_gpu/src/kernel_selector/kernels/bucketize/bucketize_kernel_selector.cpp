// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "bucketize_kernel_selector.hpp"

namespace kernel_selector {

bucketize_kernel_selector::bucketize_kernel_selector() { }

KernelsData bucketize_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::BUCKETIZE);
}

}  // namespace kernel_selector
