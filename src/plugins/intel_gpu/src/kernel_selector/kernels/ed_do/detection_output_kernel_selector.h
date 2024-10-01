// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "detection_output_kernel_ref.h"

namespace kernel_selector {
class experimental_detectron_detection_output_kernel_selector : public kernel_selector_base {
public:
    static experimental_detectron_detection_output_kernel_selector& Instance() {
        static experimental_detectron_detection_output_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &ExperimentalDetectronDetectionOutputKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    experimental_detectron_detection_output_kernel_selector();

    KernelsData GetBestKernels(const Params& params) const override;
};

}  // namespace kernel_selector
