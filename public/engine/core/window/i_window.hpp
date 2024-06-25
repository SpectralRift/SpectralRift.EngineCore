#pragma once

#include <string_view>
#include <memory>

#include <engine/core/utils/vector2.hpp>
#include <engine/core/graphics/i_graphics_context.hpp>

namespace engine {
    namespace core {
        struct IWindow {
            IWindow() : b_HasRequiredQuit{false}, m_GfxContext{nullptr} {}

            ~IWindow() = default;

            virtual bool init() = 0;

            virtual void destroy() = 0;

            virtual void setTitle(std::string_view title) = 0;

            virtual void setPosition(utils::IVector2 position) = 0;

            virtual void setSize(utils::IVector2 size) = 0;

            virtual utils::IVector2 getPosition() = 0;

            virtual utils::IVector2 getSize() = 0;

            virtual void processEvents() = 0;

            virtual void show() = 0;

            virtual void hide() = 0;

            bool hasRequiredQuit() const {
                return b_HasRequiredQuit;
            }

            IGraphicsContext *getGraphicsContext() const {
                return m_GfxContext.get();
            }

        protected:
            bool b_HasRequiredQuit;
            std::unique_ptr<IGraphicsContext> m_GfxContext;
        };
    }
}