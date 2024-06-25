#pragma once

#include <engine/core/utils/factory.hpp>

namespace engine {
    namespace core {
        namespace utils {
            template<typename T>
            struct SingletonFactory : public Factory<T>{
                SingletonFactory() = delete;

                static std::shared_ptr<T> get() {
                    static std::shared_ptr<T> m_Instance;

                    if (!m_Instance) {
                        m_Instance = std::move(Factory<T>::create());
                    }

                    return m_Instance;
                }
            };
        }
    }
}