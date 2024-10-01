// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "detection_output_kernel_ref.h"

namespace kernel_selector {
class detection_output_kernel_selector : public kernel_selector_base {
public:
    static detection_output_kernel_selector& Instance() {
        static detection_output_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &DetectionOutputKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    detection_output_kernel_selector();

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
