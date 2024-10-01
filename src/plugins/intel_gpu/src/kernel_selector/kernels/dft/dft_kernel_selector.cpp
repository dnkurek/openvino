// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "dft_kernel_selector.h"

namespace kernel_selector {

dft_kernel_selector::dft_kernel_selector() { }

KernelsData dft_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::DFT);
}

}  // namespace kernel_selector
