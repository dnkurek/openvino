// Copyright (C) 2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "swiglu_kernel_ref.h"
#include "swiglu_kernel_opt.h"

namespace kernel_selector {
class swiglu_kernel_selector : public kernel_selector_base {
public:
    static swiglu_kernel_selector& Instance() {
        static swiglu_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &SwiGLUKernelRef::Instance(), &SwiGLUKernelOpt::Instance() };
	static struct ImplementationList impls = { list, 2 };

	return &impls;
    }

    swiglu_kernel_selector();

    virtual ~swiglu_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
