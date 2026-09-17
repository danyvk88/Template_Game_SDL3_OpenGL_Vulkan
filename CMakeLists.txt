cmake_minimum_required(VERSION 3.25)

project(
    SDL3OpenGLVulkanTemplate
    VERSION 0.1.0
    DESCRIPTION "Reusable C++23 game template built with SDL3"
    LANGUAGES C CXX
)

include(FetchContent)

# Build SDL as a static dependency for the first desktop milestone. The SDL
# sources stay in CMake's build directory and are not added to this repository.
set(SDL_SHARED OFF CACHE BOOL "Build the SDL shared library" FORCE)
set(SDL_STATIC ON CACHE BOOL "Build the SDL static library" FORCE)
set(SDL_TEST_LIBRARY OFF CACHE BOOL "Build the SDL test library" FORCE)
set(SDL_TESTS OFF CACHE BOOL "Build the SDL test programs" FORCE)
set(SDL_EXAMPLES OFF CACHE BOOL "Build the SDL example programs" FORCE)
set(SDL_INSTALL OFF CACHE BOOL "Create SDL installation targets" FORCE)
set(SDL_UNINSTALL OFF CACHE BOOL "Create the SDL uninstall target" FORCE)

FetchContent_Declare(
    SDL3
    URL
        https://github.com/libsdl-org/SDL/releases/download/release-3.4.16/SDL3-3.4.16.tar.gz
    URL_HASH
        SHA256=7322236cd12090c3eb40b9728be4d49c76f66ad17d04369584d4ecad5cf77c68
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    TLS_VERIFY TRUE
)

FetchContent_MakeAvailable(SDL3)

add_executable(game src/main.cpp)

set_target_properties(
    game
    PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
)

target_link_libraries(game PRIVATE SDL3::SDL3)

if(MSVC)
    target_compile_options(game PRIVATE /W4 /permissive- /utf-8)
else()
    target_compile_options(game PRIVATE -Wall -Wextra -Wpedantic)
endif()
