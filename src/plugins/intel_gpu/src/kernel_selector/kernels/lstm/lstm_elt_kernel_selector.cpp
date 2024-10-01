// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "lstm_elt_kernel_selector.h"

namespace kernel_selector {
lstm_elt_kernel_selector::lstm_elt_kernel_selector() { }

KernelsData lstm_elt_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::LSTM_ELT);
}
}  // namespace kernel_selector
