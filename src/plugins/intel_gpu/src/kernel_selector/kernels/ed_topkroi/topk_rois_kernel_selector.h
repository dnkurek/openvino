// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "topk_rois_ref.h"

namespace kernel_selector {

/**
 * GPU kernel selector for the ExperimentalDetectronTopKROIS-6 operation
 */
class experimental_detectron_topk_rois_kernel_selector : public kernel_selector_base {
public:
    static experimental_detectron_topk_rois_kernel_selector& Instance() {
        static experimental_detectron_topk_rois_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &ExperimentalDetectronTopKROIRef::Instance() };
	static struct ImplementationList impls = { list, 2 };

	return &impls;
    }

    experimental_detectron_topk_rois_kernel_selector();

    KernelsData GetBestKernels(const Params &params) const override;
};
}  // namespace kernel_selector
