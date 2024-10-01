// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "ctc_greedy_decoder_kernel_selector.h"

namespace kernel_selector {
ctc_greedy_decoder_kernel_selector::ctc_greedy_decoder_kernel_selector() {
}

KernelsData ctc_greedy_decoder_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::CTC_GREEDY_DECODER);
}
}  // namespace kernel_selector
