// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "broadcast_kernel_ref.h"

namespace kernel_selector {
class broadcast_kernel_selector : public kernel_selector_base {
public:
    static broadcast_kernel_selector& Instance() {
        static broadcast_kernel_selector instance;
        return instance;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &BroadcastKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    broadcast_kernel_selector();

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
