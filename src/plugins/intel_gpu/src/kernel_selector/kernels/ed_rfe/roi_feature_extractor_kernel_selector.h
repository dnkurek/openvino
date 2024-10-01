// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "roi_feature_extractor_kernel_ref.h"

namespace kernel_selector {
class experimental_detectron_roi_feature_extractor_kernel_selector : public kernel_selector_base {
public:
    static experimental_detectron_roi_feature_extractor_kernel_selector& Instance() {
        static experimental_detectron_roi_feature_extractor_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &ExperimentalDetectronROIFeatureExtractorRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    experimental_detectron_roi_feature_extractor_kernel_selector();
    ~experimental_detectron_roi_feature_extractor_kernel_selector() = default;

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
