// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "kernel_base.h"
#include "kernel_selector_common.h"
#include "kernel_selector.h"
#include "kernel_selector_params.h"
#include <type_traits>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <set>
#include <iostream>
#include "intel_gpu/runtime/debug_configuration.hpp"

// #define ENABLE_ENV
// #define ENABLE_ENV_PRINT

#ifdef ENABLE_ENV_PRINT
#define ENV_PRINTF(...) printf(__VA_ARGS__)
#else
#define ENV_PRINTF(...)
#endif  // ENABLE_ENV_PRINT

#define ENABLE_OFFLINE_TUNING_CACHE 1

namespace kernel_selector {

AutoTuner kernel_selector_base::autoTuner;

#ifdef ENABLE_ENV
std::string strip(const std::string str) {
    size_t start = str.find_first_not_of(' ');
    size_t end = str.find_last_not_of(' ');
    if (start == std::string::npos || end == std::string::npos) {
        return "";
    }

    return str.substr(start, end - start + 1);
}

static void AddToForceMap(ForceList& force_list, bool force_or_deny, const char* env_str) {
    std::stringstream ss;
    ss.str(GetStringEnv(env_str));

    ENV_PRINTF("ENV: %s = %s\n", env_str, ss.str().c_str());

    std::string val;
    while (std::getline(ss, val, ',')) {
        std::string kernel_name = strip(val);
        if (!kernel_name.empty()) {
            force_list[kernel_name] = force_or_deny;
        }
    }
}
#endif

kernel_selector_base::kernel_selector_base() {
#ifdef ENABLE_ENV
    AddToForceMap(forceKernels, true, "CL_DNN_FORCE_KERNELS");
    AddToForceMap(forceKernels, false, "CL_DNN_DENY_KERNELS");
#endif
}

KernelData kernel_selector_base::get_best_kernel(const Params& params) const {
    auto kernels = GetBestKernels(params);
    OPENVINO_ASSERT(!kernels.empty(), "[GPU] Could not find a suitable kernel for ", params.layerID, " params raw string: ", params.to_cache_string_v2());
    return kernels[0];
}


KernelsData kernel_selector_base::GetNaiveBestKernel(const struct ImplementationList* all_impls, const Params& params) const {
    KernelsData kernelsData;
    std::string kernelName;

    for (int i = 0; i < all_impls->len; i++) {
        // TODO: Unify this check with the Validate virtual method. Make
        // sure that the method is called here only, not in all the
        // GetKernelsData implementations.
        try {
            KernelsData kds = all_impls->ptr[i]->GetKernelsData(params);

            if (kds.size() && kds[0].kernels.size()) {
                kernelsData = kds;
                kernelName = all_impls->ptr[i]->GetName();
                break;
            }
        } catch (std::runtime_error& ex) {
            // we have to handle it in order to avoid exception in KernelSelector as much we can
            kernelName = (all_impls->ptr[i] != nullptr)? all_impls->ptr[i]->GetName() : "[impl is null]";
            GPU_DEBUG_TRACE << "layerID: " << params.layerID << " kernel: " << kernelName << " - " << ex.what() << std::endl;
        }
    }

    // TODO: find a better place to located this assignment
    if (kernelsData.size()) {
        kernelsData[0].kernelName = kernelName;
        kernelsData[0].kernels[0].params.layerID = params.layerID;
    }

    return kernelsData;
}
KernelsData kernel_selector_base::GetNaiveBestKernel(const Params& params, KernelType kType) const {
    return GetNaiveBestKernel(GetAllImplementations(params, kType), params);
}

KernelsData kernel_selector_base::GetAutoTuneBestKernel(const Params& params, KernelType kType) const {
    KernelsData kernelsData;
    std::string kernelName;

    struct ImplementationList* allImplementations = GetAllImplementations(params, kType);
    auto kernel_params = static_cast<const base_params&>(params);
    bool int8_kernel = kernel_params.inputs[0].GetDType() == Datatype::INT8 || kernel_params.inputs[0].GetDType() == Datatype::UINT8;
    std::tuple<std::string, int> cachedKernelConfig;
    if (!int8_kernel) {  // Try to load kernel/config from offline cache
        cachedKernelConfig = autoTuner.LoadKernelOffline(params);
    }
    bool hashFoundInCache = !std::get<0>(cachedKernelConfig).empty();

    if (hashFoundInCache) {
        std::string cachedkernelName = std::get<0>(cachedKernelConfig);
        int autoTuneIndex = std::get<1>(cachedKernelConfig);

        for (int i = 0; i < allImplementations->len; i++) {
            // TODO: make sure kernel names are unique.
            if (allImplementations->ptr[i]->GetName().compare(cachedkernelName) == 0) {
                KernelsData kds = allImplementations->ptr[i]->GetTunedKernelsDataByIndex(params, autoTuneIndex);
                if (kds.size() && kds[0].kernels.size()) {
                    kernelsData = kds;
                    kernelsData[0].kernelName = cachedkernelName;
                    kernelsData[0].kernels[0].params.layerID = params.layerID;
                }
                break;
            }
        }

        if (!kernelsData.empty()) {
            return kernelsData;
        }
    }

    return GetNaiveBestKernel(allImplementations, params);
}

KernelBase* kernel_selector_base::GetImplementation(std::string& kernel_name) const {
    struct ImplementationList* impls = GetImpls();
    for (int i = 0; i < impls->len; i++) {
        if (impls->ptr[i]->GetName().compare(kernel_name) == 0)
            return impls->ptr[i];
    }
    return nullptr;
}

struct ImplementationList* kernel_selector_base::GetAllImplementations(const Params& params, KernelType kType) const {
	struct ImplementationList* impls = GetImpls();
	return impls;
}

}  // namespace kernel_selector
