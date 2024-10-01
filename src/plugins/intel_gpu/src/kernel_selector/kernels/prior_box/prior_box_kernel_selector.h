// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "kernel_selector.h"
#include "prior_box_kernel_ref.h"

#pragma once

namespace kernel_selector {

/**
 * GPU kernel selector for the PriorBox operation
 */
class prior_box_kernel_selector : public kernel_selector_base {
public:
    static prior_box_kernel_selector& Instance() {
        static prior_box_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &PriorBoxKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    KernelsData GetBestKernels(const Params& params) const override;

    prior_box_kernel_selector();
};

}  // namespace kernel_selector
