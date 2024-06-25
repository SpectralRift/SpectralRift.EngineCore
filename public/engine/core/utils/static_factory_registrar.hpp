#pragma once

#include <string>
#include <string_view>
#include <cstdio>

namespace engine {
    namespace core {
        namespace utils {
            template<typename FactoryType>
            class StaticFactoryRegistrar {
            public:
                StaticFactoryRegistrar(std::string_view name, FactoryType::FactoryMethod method) : m_FactoryName(name) {
                    FactoryType::factoryRegister(m_FactoryName, method);
                }

                ~StaticFactoryRegistrar() {
                    FactoryType::factoryUnregister(m_FactoryName);
                }
            private:
                std::string m_FactoryName;
            };
        }
    }
}