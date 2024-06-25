#pragma once

#include <string>
#include <string_view>

#include <engine/core/utils/vector2.hpp>

namespace engine {
    namespace core {
        struct DisplayInfo {
            std::string name;
            utils::IVector2 size;
            utils::IVector2 position;
            bool isPrimary;

            DisplayInfo(std::string_view name, const utils::IVector2 &size, const utils::IVector2 &position, bool isPrimary) :
                    name(name), size(size), position(position), isPrimary(isPrimary) {}
        };
    }
}