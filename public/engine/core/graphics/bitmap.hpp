#pragma once

#include <engine/core/utils/vector2.hpp>
#include <engine/core/utils/color.hpp>

namespace engine::core::graphics {
    struct Bitmap {
        Bitmap() = default;

        Bitmap(const std::vector<Color>& data, const utils::IVector2& size)
            : m_Data{data}, m_Size{size} {}

        Bitmap(const Bitmap& other)
            : m_Data{other.m_Data}, m_Size{other.m_Size} {}

        Bitmap& operator=(const Bitmap& other) {
            m_Data = other.m_Data;
            m_Size = other.m_Size;
            return *this;
        }

        const std::vector<Color>& getData() const {
            return m_Data;
        }

        const utils::IVector2& getSize() const {
            return m_Size;
        }
    protected:
        std::vector<Color> m_Data;
        utils::IVector2 m_Size;
    };
}