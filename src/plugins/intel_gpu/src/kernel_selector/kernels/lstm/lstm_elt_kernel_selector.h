// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "lstm_elt_kernel_ref.h"

namespace kernel_selector {
class lstm_elt_kernel_selector : public kernel_selector_base {
public:
    static lstm_elt_kernel_selector& Instance() {
        static lstm_elt_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &LSTMEltKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    lstm_elt_kernel_selector();

    virtual ~lstm_elt_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
