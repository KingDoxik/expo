/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <ABI45_0_0React/ABI45_0_0debug/ABI45_0_0React_native_assert.h>
#include <ABI45_0_0React/ABI45_0_0renderer/components/inputaccessory/InputAccessoryShadowNode.h>
#include <ABI45_0_0React/ABI45_0_0renderer/core/ConcreteComponentDescriptor.h>

namespace ABI45_0_0facebook {
namespace ABI45_0_0React {

/*
 * Descriptor for <InputAccessoryView> component.
 */
class InputAccessoryComponentDescriptor final
    : public ConcreteComponentDescriptor<InputAccessoryShadowNode> {
 public:
  using ConcreteComponentDescriptor::ConcreteComponentDescriptor;

  void adopt(ShadowNode::Unshared const &shadowNode) const override {
    auto concreteShadowNode =
        std::static_pointer_cast<InputAccessoryShadowNode>(shadowNode);

    auto layoutableShadowNode =
        std::static_pointer_cast<YogaLayoutableShadowNode>(concreteShadowNode);

    auto state =
        std::static_pointer_cast<const InputAccessoryShadowNode::ConcreteState>(
            shadowNode->getState());
    auto stateData = state->getData();

    layoutableShadowNode->setSize(
        Size{stateData.viewportSize.width, stateData.viewportSize.height});
    layoutableShadowNode->setPositionType(ABI45_0_0YGPositionTypeAbsolute);

    ConcreteComponentDescriptor::adopt(shadowNode);
  }
};

} // namespace ABI45_0_0React
} // namespace ABI45_0_0facebook
