// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "extract_image_patches_kernel_ref.h"

namespace kernel_selector {
class extract_image_patches_kernel_selector : public kernel_selector_base {
public:
    static extract_image_patches_kernel_selector& Instance() {
        static extract_image_patches_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &ExtractImagePatchesKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    extract_image_patches_kernel_selector();
    virtual ~extract_image_patches_kernel_selector() = default;

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
