/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "ABI45_0_0TurboModule.h"

using namespace ABI45_0_0facebook;

namespace ABI45_0_0facebook {
namespace ABI45_0_0React {

TurboModule::TurboModule(
    const std::string &name,
    std::shared_ptr<CallInvoker> jsInvoker)
    : name_(name), jsInvoker_(jsInvoker) {}

TurboModule::~TurboModule() {}

jsi::Value TurboModule::get(
    jsi::Runtime &runtime,
    const jsi::PropNameID &propName) {
  std::string propNameUtf8 = propName.utf8(runtime);
  auto p = methodMap_.find(propNameUtf8);
  if (p == methodMap_.end()) {
    // Method was not found, let JS decide what to do.
    return jsi::Value::undefined();
  }
  MethodMetadata meta = p->second;
  return jsi::Function::createFromHostFunction(
      runtime,
      propName,
      static_cast<unsigned int>(meta.argCount),
      [this, meta](
          ABI45_0_0facebook::jsi::Runtime &rt,
          const ABI45_0_0facebook::jsi::Value &thisVal,
          const ABI45_0_0facebook::jsi::Value *args,
          size_t count) { return meta.invoker(rt, *this, args, count); });
}

} // namespace ABI45_0_0React
} // namespace ABI45_0_0facebook
