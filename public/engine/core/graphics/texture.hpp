#pragma once

#include <cstdint>
#include <memory>

#include <engine/core/graphics/bitmap.hpp>
#include <engine/core/utils/vector2.hpp>

namespace engine::core::graphics {
    struct ITexture {
        virtual void uploadData(const Bitmap& data) = 0;
        virtual Bitmap getData() = 0;

        virtual void bind(uint16_t samplerSlot = 0) = 0;
        virtual void unbind() = 0;

        virtual utils::IVector2 getSize() = 0;
    };
}