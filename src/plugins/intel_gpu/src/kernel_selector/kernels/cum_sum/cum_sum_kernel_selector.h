// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "cum_sum_kernel_ref.h"
#include "cum_sum_kernel_partial_sum.h"

namespace kernel_selector {
class cum_sum_kernel_selector : public kernel_selector_base {
public:
    static cum_sum_kernel_selector& Instance() {
        static cum_sum_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &CumSumKernelRef::Instance(), &CumSumKernelPartialSum::Instance() };
	static struct ImplementationList impls = { list, 2 };

	return &impls;
    }

    cum_sum_kernel_selector();
    virtual ~cum_sum_kernel_selector() = default;

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
