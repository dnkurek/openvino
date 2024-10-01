// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "softmax_kernel_ref.h"
#include "softmax_kernel_bf.h"
#include "softmax_kernel_fb.h"
#include "softmax_kernel_items_class_optimized.h"

namespace kernel_selector {
class softmax_kernel_selector : public kernel_selector_base {
public:
    static softmax_kernel_selector& Instance() {
        static softmax_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = {
		&SoftmaxKernelRef::Instance(),
		&SoftmaxKernel_bf::Instance(),
		&SoftmaxKernel_fb::Instance(),
		&SoftmaxKerneItemsClassOptimized::Instance()
	};
	static struct ImplementationList impls = { list, 4 };

	return &impls;
    }


    softmax_kernel_selector();

    virtual ~softmax_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
