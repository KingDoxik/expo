#pragma once

#include <memory>
#include <utility>

#include <ABI46_0_0jsi/ABI46_0_0jsi.h>

#include <JsiSkHostObjects.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

#include <SkGradientShader.h>
#include <SkShader.h>

#pragma clang diagnostic pop

namespace ABI46_0_0RNSkia {

using namespace ABI46_0_0facebook;

class JsiSkShader : public JsiSkWrappingSkPtrHostObject<SkShader> {
public:
  JsiSkShader(std::shared_ptr<ABI46_0_0RNSkPlatformContext> context,
              sk_sp<SkShader> shader)
      : JsiSkWrappingSkPtrHostObject<SkShader>(std::move(context), std::move(shader)) {}

  // TODO: declare in JsiSkWrappingSkPtrHostObject via extra template parameter?
  JSI_PROPERTY_GET(__typename__) {
    return jsi::String::createFromUtf8(runtime, "Shader");
  }

  JSI_EXPORT_PROPERTY_GETTERS(JSI_EXPORT_PROP_GET(JsiSkShader, __typename__))

  /**
    Returns the underlying object from a host object of this type
   */
  static sk_sp<SkShader> fromValue(jsi::Runtime &runtime,
                                   const jsi::Value &obj) {
    return obj.asObject(runtime)
        .asHostObject<JsiSkShader>(runtime)
        ->getObject();
  }
};
} // namespace ABI46_0_0RNSkia
