cmake_minimum_required(VERSION 3.14)
project(EngineCore VERSION 0.8.7)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(EngineCore STATIC private/engine/core/application.cpp)

target_include_directories(
        EngineCore
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/public"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/private"
)

target_compile_definitions(
        EngineCore
        PRIVATE ENGINE_BUILD_LIBRARY
)