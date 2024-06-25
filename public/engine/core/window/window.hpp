#pragma once

#include <engine/core/utils/factory.hpp>
#include <engine/core/window/i_window.hpp>

namespace engine {
    namespace core {
        struct Window : public utils::Factory<IWindow> {};
    }
}