// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "matrix_nms_kernel_ref.h"

namespace kernel_selector {
class matrix_nms_kernel_selector : public kernel_selector_base {
public:
    static matrix_nms_kernel_selector& Instance() {
        static matrix_nms_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &MatrixNmsKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    matrix_nms_kernel_selector();

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
