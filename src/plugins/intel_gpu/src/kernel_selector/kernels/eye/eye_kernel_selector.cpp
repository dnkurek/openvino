// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//
#include "eye_kernel_selector.h"

namespace kernel_selector {

eye_kernel_selector::eye_kernel_selector() { }

KernelsData eye_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::EYE);
}

}  // namespace kernel_selector
