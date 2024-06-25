#pragma once

#include <memory>
#include <functional>
#include <string_view>
#include <string>
#include <map>

namespace engine::core::utils {
    template<typename T>
    class Factory {
    public:
        Factory() = delete;

        using FactoryMethod = std::function<std::unique_ptr<T>()>;

        static bool factoryRegister(std::string_view name, FactoryMethod method) {
            if (getFactories().empty() || getFactories().find(name.data()) == getFactories().end()) {
                getFactories().insert(std::make_pair(name.data(), method));
                return true;
            }
            return false;
        }

        static bool factoryUnregister(std::string_view name) {
            if (getFactories().find(name.data()) != getFactories().end()) {
                getFactories().erase(name.data());
                return true;
            }
            return false;
        }

        static std::unique_ptr <T> create() {
            if (!getFactories().empty()) {
                if (!getPreferDefault().empty() &&
                    getFactories().find(getPreferDefault().data()) != getFactories().end()) {
                    getHasCreated() = true;
                    return getFactories()[getPreferDefault()]();
                }

                getHasCreated() = true;
                return getFactories().begin()->second();
            }

            return nullptr;
        }

        static std::unique_ptr <T> createPref(std::string_view name) {
            if (getFactories().find(name.data()) != getFactories().end()) {
                getHasCreated() = true;
                return getFactories()[name]();
            }
            return nullptr;
        }

        static void prefer(std::string_view name) {
            if (getHasCreated()) return;
            getPreferDefault() = name;
        }

    protected:
        // using "construct on first use" method here to prevent static init order issues
        static std::map <std::string, FactoryMethod> &getFactories() {
            static std::map<std::string, FactoryMethod> m_Factories;
            return m_Factories;
        }

        static std::string &getPreferDefault() {
            static std::string m_PreferDefault;
            return m_PreferDefault;
        }

        static bool &getHasCreated() {
            static bool b_HasCreated = false;
            return b_HasCreated;
        }
    };
}