// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "count_nonzero_kernel_ref.h"

namespace kernel_selector {
class count_nonzero_kernel_selector : public kernel_selector_base {
public:
    static count_nonzero_kernel_selector& Instance() {
        static count_nonzero_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &CountNonzeroKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    count_nonzero_kernel_selector();

    virtual ~count_nonzero_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
