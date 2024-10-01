// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "reduce_kernel_ref.h"
#include "reduce_kernel_b_fs_yx_fsv16.h"
#include "reduce_kernel_simple_to_scalar.h"

namespace kernel_selector {
class reduce_kernel_selector : public kernel_selector_base {
public:
    static reduce_kernel_selector& Instance() {
        static reduce_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = {
		&ReduceKernelRef::Instance(),
		&ReduceKernel_b_fs_yx_fsv16::Instance(),
		&ReduceKernelSimpleToScalar::Instance()
	};
	static struct ImplementationList impls = { list, 3 };

	return &impls;
    }

    reduce_kernel_selector();

    virtual ~reduce_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
