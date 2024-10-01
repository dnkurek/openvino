// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "region_yolo_kernel_ref.h"

namespace kernel_selector {
class region_yolo_kernel_selector : public kernel_selector_base {
public:
    static region_yolo_kernel_selector& Instance() {
        static region_yolo_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &RegionYoloKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    region_yolo_kernel_selector();

    virtual ~region_yolo_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
