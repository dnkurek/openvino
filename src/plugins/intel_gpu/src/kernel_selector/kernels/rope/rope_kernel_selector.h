// Copyright (C) 2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "rope_kernel_ref.h"

namespace kernel_selector {
class rope_kernel_selector : public kernel_selector_base {
public:
    static rope_kernel_selector& Instance() {
        static rope_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &RoPEKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    rope_kernel_selector();

    virtual ~rope_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
