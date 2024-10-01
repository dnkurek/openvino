// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "sdpa_kernel_ref.h"

#include "pa_sdpa_kernel_opt.h"
#include "pa_kv_cache_update_kernel_ref.h"

namespace kernel_selector {
class sdpa_kernel_selector : public kernel_selector_base {
public:
    static sdpa_kernel_selector& Instance() {
        static sdpa_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &SDPAKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    sdpa_kernel_selector();

    virtual ~sdpa_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};

class kv_cache_update_kernel_selector : public kernel_selector_base {
public:
    static kv_cache_update_kernel_selector& Instance() {
        static kv_cache_update_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &KVCacheUpdateKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    kv_cache_update_kernel_selector();

    virtual ~kv_cache_update_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};

class pa_sdpa_kernel_selector : public kernel_selector_base {
public:
    static pa_sdpa_kernel_selector& Instance() {
        static pa_sdpa_kernel_selector instance_;
        return instance_;
    }
    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &PagedAttentionSDPAKernelOpt::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    pa_sdpa_kernel_selector();

    virtual ~pa_sdpa_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
