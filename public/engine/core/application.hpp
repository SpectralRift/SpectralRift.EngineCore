#pragma once

namespace engine {
    namespace core {
        class Application {
        public:
            virtual ~Application() = default;

            int run();

            void stop();

            bool isRunning() const {
                return b_Running;
            }

        protected:
            virtual int init();

            virtual void loop();

            virtual void shutdown();

        private:
            bool b_Running = false;
        };
    }
}