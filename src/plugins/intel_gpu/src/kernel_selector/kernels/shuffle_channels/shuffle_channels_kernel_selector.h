// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "shuffle_channels_kernel_ref.h"

namespace kernel_selector {
class shuffle_channels_kernel_selector : public kernel_selector_base {
public:
    static shuffle_channels_kernel_selector& Instance() {
        static shuffle_channels_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &ShuffleChannelsKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    shuffle_channels_kernel_selector();

    virtual ~shuffle_channels_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
