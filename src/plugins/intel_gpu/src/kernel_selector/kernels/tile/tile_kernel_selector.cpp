// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "tile_kernel_selector.h"

namespace kernel_selector {

tile_kernel_selector::tile_kernel_selector() { }

KernelsData tile_kernel_selector::GetBestKernels(const Params& params) const {
    return GetNaiveBestKernel(params, KernelType::TILE);
}
}  // namespace kernel_selector
