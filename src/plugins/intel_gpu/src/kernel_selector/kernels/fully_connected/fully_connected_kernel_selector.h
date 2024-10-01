// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "fully_connected_kernel_bfyx_ref.h"

namespace kernel_selector {
class fully_connected_kernel_selector : public kernel_selector_base {
public:
    static fully_connected_kernel_selector& Instance() {
        static fully_connected_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &FullyConnected_bfyx_Ref::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    fully_connected_kernel_selector();

    virtual ~fully_connected_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
