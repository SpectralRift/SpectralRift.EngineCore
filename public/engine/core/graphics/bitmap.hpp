#pragma once

#include <engine/core/utils/vector2.hpp>
#include <engine/core/utils/color.hpp>

namespace engine::core::graphics {
    struct Bitmap {
        Bitmap() = default;

        Bitmap(const std::vector<utils::Color> &data, const utils::IVector2 &size)
                : m_Data{data}, m_Size{size} {}

        Bitmap(const Bitmap &other)
                : m_Data{other.m_Data}, m_Size{other.m_Size} {}

        Bitmap &operator=(const Bitmap &other) {
            m_Data = other.m_Data;
            m_Size = other.m_Size;
            return *this;
        }

        const std::vector<utils::Color> &getData() const {
            return m_Data;
        }

        void setData(const std::vector<utils::Color> &data) {
            m_Data = data;
        }

        const utils::IVector2 &getSize() const {
            return m_Size;
        }

        void setSize(const utils::IVector2 &size) {
            m_Size = size;
        }

        const utils::Color &getPixel(const utils::IVector2 &pos) const {
            return m_Data[pos.y * m_Size.x + pos.x];
        }

        void setPixel(const utils::IVector2 &pos, const utils::Color &color) {
            m_Data[pos.y * m_Size.x + pos.x] = color;
        }

    protected:
        utils::IVector2 m_Size;
        std::vector<utils::Color> m_Data;
    };
}