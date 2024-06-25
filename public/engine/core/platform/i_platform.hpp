#pragma once

#include <vector>
#include <string_view>

#include <engine/core/graphics/display_info.hpp>

namespace engine {
    namespace core {
        struct IPlatform {
            virtual ~IPlatform() = default;

            virtual void init() {}
            virtual void shutdown() {}

//            virtual std::vector<DisplayInfo> getAvailableDisplays() = 0;
//
//            virtual DisplayInfo getPrimaryDisplay() = 0;
//
            virtual std::string getName() const = 0;

            virtual void showMessageBox(std::string_view title, std::string_view message) = 0;
        };
    }
}