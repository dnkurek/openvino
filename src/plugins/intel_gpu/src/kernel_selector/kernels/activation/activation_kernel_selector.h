// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "activation_kernel_opt.h"
#include "activation_kernel_ref.h"

namespace kernel_selector {
class activation_kernel_selector : public kernel_selector_base {
public:
    static activation_kernel_selector& Instance() {
        static activation_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &ActivationKernelRef::Instance(), &ActivationKernelOpt::Instance() };
	static struct ImplementationList impls = { list, 2 };

	return &impls;
    }

    activation_kernel_selector();

    virtual ~activation_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
