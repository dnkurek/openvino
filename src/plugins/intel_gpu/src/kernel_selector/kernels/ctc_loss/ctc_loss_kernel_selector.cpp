// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "ctc_loss_kernel_selector.hpp"

namespace kernel_selector {

ctc_loss_kernel_selector::ctc_loss_kernel_selector() { }

KernelsData ctc_loss_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::CTC_LOSS);
}

}  // namespace kernel_selector
