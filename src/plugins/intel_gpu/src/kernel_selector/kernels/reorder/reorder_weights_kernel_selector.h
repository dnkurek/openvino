// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "reorder_weights_kernel.h"
#include "reorder_weights_winograd_2x3_kernel.h"
#include "reorder_weights_winograd_6x3_kernel.h"
#include "reorder_weights_image_fyx_b_kernel.h"
#include "reorder_weights_image_winograd_6x3_kernel.h"
#include "reorder_weights_opt.h"
#include "reorder_weights_int4.h"

namespace kernel_selector {
class ReorderWeightsKernelSelector : public kernel_selector_base {
public:
    static ReorderWeightsKernelSelector& Instance() {
        static ReorderWeightsKernelSelector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = {
		&ReorderWeightsKernel::Instance(),
		&ReorderWeightsWinograd2x3Kernel::Instance(),
		&ReorderWeightsWinograd6x3Kernel::Instance(),
		&ReorderWeightsImage_fyx_b_Kernel::Instance(),
		&ReorderWeightsImageWinograd6x3Kernel::Instance(),
		&ReorderWeightsOpt::Instance(),
		&ReorderWeightsKernelInt4::Instance(),
	};
	static struct ImplementationList impls = { list, 7 };

	return &impls;
    }

    ReorderWeightsKernelSelector();

    virtual ~ReorderWeightsKernelSelector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
