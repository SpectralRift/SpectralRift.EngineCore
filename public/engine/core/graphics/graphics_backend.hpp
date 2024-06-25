#pragma once

#include <engine/core/graphics/i_graphics_backend.hpp>
#include <engine/core/utils/singleton_factory.hpp>

namespace engine {
    namespace core {
        struct GraphicsBackend : public utils::SingletonFactory<graphics::IGraphicsBackend> {
        };
    }
}