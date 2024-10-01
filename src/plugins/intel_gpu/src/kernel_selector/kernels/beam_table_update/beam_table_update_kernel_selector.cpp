// Copyright (C) 2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "beam_table_update_kernel_selector.hpp"

namespace kernel_selector {

beam_table_update_kernel_selector::beam_table_update_kernel_selector() { }

KernelsData beam_table_update_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::BEAM_TABLE_UPDATE);
}

}  // namespace kernel_selector
