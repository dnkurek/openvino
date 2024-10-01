// Copyright (C) 2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "beam_table_update_kernel_ref.hpp"

namespace kernel_selector {

class beam_table_update_kernel_selector : public kernel_selector_base {
public:
    static beam_table_update_kernel_selector& Instance() {
        static beam_table_update_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &BeamTableUpdateKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    beam_table_update_kernel_selector();
    KernelsData GetBestKernels(const Params& params) const override;
};

}  // namespace kernel_selector
