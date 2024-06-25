#pragma once

#include <engine/core/utils/singleton_factory.hpp>
#include <engine/core/platform/i_platform.hpp>

namespace engine {
    namespace core {
        struct Platform : public utils::SingletonFactory<IPlatform> {
            static std::string getName() {
                return get()->getName();
            };

            static void showMessageBox(std::string_view title, std::string_view message) {
                return get()->showMessageBox(title, message);
            };

            static void init() {
                return get()->init();
            }

            static void shutdown() {
                return get()->shutdown();
            }
        };
    }
}