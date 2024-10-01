// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once
#include "kernel_selector.h"
#include "bucketize_kernel_ref.hpp"

namespace kernel_selector {

/*
 * Bucketize kernel selector.
 */
class bucketize_kernel_selector : public kernel_selector_base {
public:
    static bucketize_kernel_selector& Instance() {
        static bucketize_kernel_selector instance;
        return instance;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &BucketizeKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    bucketize_kernel_selector();
    KernelsData GetBestKernels(const Params& params) const override;
};

}  // namespace kernel_selector
