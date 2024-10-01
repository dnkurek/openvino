// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector_common.h"
#include "auto_tuner.h"
#include <vector>
#include <memory>
#include <string>
#include <map>

namespace kernel_selector {
class KernelBase;

using ForceList = std::map<std::string, bool>;

    struct ImplementationList {
	KernelBase **ptr;
	int len;
    };

class kernel_selector_base {
public:

    kernel_selector_base();
    virtual ~kernel_selector_base() {}

    KernelData get_best_kernel(const Params& params) const;
    KernelBase* GetImplementation(std::string& kernel_name) const;

protected:
    template <typename T>
    inline void Attach() {
        //implementations.push_back(T::Instance());
    }
    virtual KernelsData GetBestKernels(const Params& params) const = 0;

    KernelsData GetNaiveBestKernel(const struct ImplementationList* all_impls,
                                   const Params& params) const;

    KernelsData GetNaiveBestKernel(const Params& params,
                                   KernelType kType) const;

    KernelsData GetAutoTuneBestKernel(const Params& params,
                                      KernelType kType) const;

    struct ImplementationList* GetAllImplementations(const Params& params, KernelType kType) const;

    virtual struct ImplementationList* GetImpls() const = 0;

    ForceList forceKernels;

    static AutoTuner autoTuner;
};
}  // namespace kernel_selector
