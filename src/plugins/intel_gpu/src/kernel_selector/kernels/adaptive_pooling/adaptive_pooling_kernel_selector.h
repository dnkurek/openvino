// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "adaptive_pooling_kernel_ref.h"

namespace kernel_selector {
class adaptive_pooling_kernel_selector : public kernel_selector_base {
public:
    static adaptive_pooling_kernel_selector& Instance();

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &AdaptivePoolingRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    adaptive_pooling_kernel_selector();

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
