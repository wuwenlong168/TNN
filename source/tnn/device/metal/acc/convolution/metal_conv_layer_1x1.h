// Tencent is pleased to support the open source community by making TNN available.
//
// Copyright (C) 2020 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#ifndef TNN_SOURCE_TNN_DEVICE_METAL_METAL_CONV_LAYER_ACC_1x1_H_
#define TNN_SOURCE_TNN_DEVICE_METAL_METAL_CONV_LAYER_ACC_1x1_H_

#include "tnn/device/metal/acc/convolution/metal_conv_layer_common.h"

namespace TNN_NS {

// @brief conv layer metal acc
class MetalConvLayer1x1 : public MetalConvLayerCommon {
public:
    virtual ~MetalConvLayer1x1();

    Status Forward(const std::vector<Blob *> &inputs, const std::vector<Blob *> &outputs);

    static bool isPrefered(ConvLayerParam *param, const std::vector<Blob *> &inputs,
                           const std::vector<Blob *> &outputs);

    Status AllocateBufferParam(const std::vector<Blob *> &inputs, const std::vector<Blob *> &outputs);
    
public:
    virtual std::string KernelName(const std::vector<Blob *> &inputs, const std::vector<Blob *> &outputs);
    virtual Status ComputeThreadSize(const std::vector<Blob *> &inputs,
                                     const std::vector<Blob *> &outputs,
                                     MTLSize &size);
    virtual Status SetKernelEncoderParam(
                                         id<MTLComputeCommandEncoder> encoder,
                                         const std::vector<Blob *> &inputs,
                                         const std::vector<Blob *> &outputs);
};

}  // namespace TNN_NS

#endif  // TNN_SOURCE_TNN_DEVICE_METAL_METAL_CONV_LAYER_ACC_1x1_H_
