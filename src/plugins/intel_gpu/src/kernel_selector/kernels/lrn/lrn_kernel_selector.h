// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "lrn_kernel_ref.h"
#include "lrn_kernel_within_channel_ref.h"
#include "lrn_kernel_within_channel_ref_opt.h"
#include "lrn_kernel_across_channel_ref.h"
#include "lrn_kernel_across_channel_opt_b8.h"
#include "lrn_kernel_across_channel_multiple_features.h"
#include "lrn_kernel_across_channel_multiple_features_fsv16.h"
#include "lrn_kernel_within_channel_byxf_opt.h"

namespace kernel_selector {
class lrn_kernel_selector : public kernel_selector_base {
public:
    static lrn_kernel_selector& Instance() {
        static lrn_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = {
		&LRNKernelRef::Instance(),
		&LRNKernelWithinChannel::Instance(),
		&LRNKernelWithinChannelOpt::Instance(),
		&LRNKernelAcrossChannelRef::Instance(),
		&LRNKernelAcrossChannel_b8::Instance(),
		&LRNKernelWithinChannelByxfOpt::Instance(),
		&LRNKernelAcrossChannelMultipleFeatures::Instance(),
		&LRNKernelAcrossChannelMultipleFeaturesFSV16::Instance()
	};
	static struct ImplementationList impls = { list, 8 };

	return &impls;
    }

    lrn_kernel_selector();

    virtual ~lrn_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
