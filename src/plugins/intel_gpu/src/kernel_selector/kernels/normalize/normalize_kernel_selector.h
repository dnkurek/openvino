// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "normalize_kernel_across_spatial_ref.h"
#include "normalize_kernel_within_spatial_ref.h"

namespace kernel_selector {
class normalize_kernel_selector : public kernel_selector_base {
public:
    static normalize_kernel_selector& Instance() {
        static normalize_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &NormalizeKernelWithinSpatialRef::Instance(), &NormalizeKernelAcrossSpatialRef::Instance() };
	static struct ImplementationList impls = { list, 2 };

	return &impls;
    }

    normalize_kernel_selector();

    virtual ~normalize_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
