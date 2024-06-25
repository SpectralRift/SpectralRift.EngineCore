#pragma once

#include <string_view>
#include <memory>

namespace engine {
    namespace core {
        struct IWindow;

        struct IGraphicsContext {
            virtual bool init() = 0;

            virtual void destroy() = 0;

            virtual void use() = 0;

            virtual void discard() = 0;

            virtual void render() = 0;
        };
    }
}