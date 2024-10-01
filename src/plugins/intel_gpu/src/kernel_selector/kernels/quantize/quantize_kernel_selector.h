// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "quantize_kernel_ref.h"
#include "quantize_kernel_scale_shift_opt.h"

namespace kernel_selector {
class quantize_kernel_selector : public kernel_selector_base {
public:
    static quantize_kernel_selector& Instance() {
        static quantize_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &QuantizeKernelRef::Instance(), &QuantizeKernelScaleShift::Instance() };
	static struct ImplementationList impls = { list, 2 };

	return &impls;
    }

    quantize_kernel_selector();

    virtual ~quantize_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
