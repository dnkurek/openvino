// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "kernel_selector.h"
#include "ctc_greedy_decoder_kernel_ref.h"

namespace kernel_selector {
class ctc_greedy_decoder_kernel_selector : public kernel_selector_base {
public:
    static ctc_greedy_decoder_kernel_selector& Instance() {
        static ctc_greedy_decoder_kernel_selector instance_;
        return instance_;
    }

    struct ImplementationList* GetImpls() const override {
	static KernelBase* list[] = { &CTCGreedyDecoderKernelRef::Instance() };
	static struct ImplementationList impls = { list, 1 };

	return &impls;
    }

    ctc_greedy_decoder_kernel_selector();
    virtual ~ctc_greedy_decoder_kernel_selector() {}

    KernelsData GetBestKernels(const Params& params) const override;
};
}  // namespace kernel_selector
