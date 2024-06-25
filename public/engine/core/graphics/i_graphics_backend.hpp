#pragma once

#include <string>

namespace engine {
    namespace core {
        namespace graphics {
            struct IGraphicsBackend {
                IGraphicsBackend() = default;
                virtual ~IGraphicsBackend() = default;

                virtual std::string getName() const = 0;
                virtual std::string getIdentifierName() const = 0;
            };
        }
    }
}
