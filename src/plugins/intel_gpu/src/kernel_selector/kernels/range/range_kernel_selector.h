// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "range_kernel_ref.h"

namespace kernel_selector {
class range_kernel_selector : public kernel_selector_base {
public:
    static range_kernel_selector& Instance() {
        static range_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &RangeKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    range_kernel_selector();

    virtual ~range_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
