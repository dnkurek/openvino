// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "arg_max_min_kernel_gpu_ref.h"
#include "arg_max_min_kernel_opt.h"
#include "arg_max_min_kernel_axis.h"

namespace kernel_selector {
class arg_max_min_kernel_selector : public kernel_selector_base {
public:
    static arg_max_min_kernel_selector& Instance() {
        static arg_max_min_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &ArgMaxMinKernelGPURef::Instance(), &ArgMaxMinKernelAxis::Instance()};
	static struct ImplementationList impls = { list, 2 };

	return &impls;
    }

    arg_max_min_kernel_selector();

    virtual ~arg_max_min_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
