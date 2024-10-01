// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "roi_pooling_kernel_ref.h"
#include "roi_pooling_kernel_ps_ref.h"

namespace kernel_selector {
class roi_pooling_kernel_selector : public kernel_selector_base {
public:
    static roi_pooling_kernel_selector& Instance() {
        static roi_pooling_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &ROIPoolingKernelRef::Instance(), &PSROIPoolingKernelRef::Instance() };
	static struct ImplementationList impls = { list, 2 };

	return &impls;
    }

    roi_pooling_kernel_selector();

    virtual ~roi_pooling_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
