// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <kernel_selector.h>
#include "dft_kernel_ref.h"

namespace kernel_selector {

class dft_kernel_selector : public kernel_selector_base {
public:
    static dft_kernel_selector& Instance() {
        static dft_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &DFTKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    dft_kernel_selector();
    KernelsData GetBestKernels(const Params& params) const override;
};

}  // namespace kernel_selector
