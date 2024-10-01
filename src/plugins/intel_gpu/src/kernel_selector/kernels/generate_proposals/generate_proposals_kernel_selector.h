// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "generate_proposals_kernel_ref.h"

namespace kernel_selector {
class generate_proposals_kernel_selector : public kernel_selector_base {
public:
    static generate_proposals_kernel_selector& Instance() {
        static generate_proposals_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &GenerateProposalsRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    generate_proposals_kernel_selector();

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
