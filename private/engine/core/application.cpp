#include <engine/core/application.hpp>

#include <cstdio>

namespace engine {
    namespace core {
        int Application::run() {
            if(isRunning()) {
                printf("Application already running!\n");
                return -1;
            }

            init();

            while(isRunning()) {
                loop();
            }

            shutdown();

            return 0;
        }

        int Application::init() {
            return 0;
        }

        void Application::loop() {

        }

        void Application::shutdown() {

        }
    }
}