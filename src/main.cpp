#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <cstdlib>

namespace {

constexpr int window_width{1280};
constexpr int window_height{720};
constexpr Uint8 background_red{24};
constexpr Uint8 background_green{32};
constexpr Uint8 background_blue{48};
constexpr Uint8 background_alpha{255};

} // namespace

int main(int, char**)
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_APPLICATION,
            "Could not initialize SDL: %s",
            SDL_GetError()
        );
        return EXIT_FAILURE;
    }

    SDL_Window* window{nullptr};
    SDL_Renderer* renderer{nullptr};

    if (!SDL_CreateWindowAndRenderer(
            "SDL3 3D Game Template",
            window_width,
            window_height,
            SDL_WINDOW_RESIZABLE,
            &window,
            &renderer
        )) {
        SDL_LogError(
            SDL_LOG_CATEGORY_APPLICATION,
            "Could not create the window and renderer: %s",
            SDL_GetError()
        );
        SDL_Quit();
        return EXIT_FAILURE;
    }

    const bool vsync_enabled{SDL_SetRenderVSync(renderer, 1)};
    if (!vsync_enabled) {
        SDL_LogWarn(
            SDL_LOG_CATEGORY_APPLICATION,
            "VSync is unavailable; using a small frame delay: %s",
            SDL_GetError()
        );
    }

    SDL_Log("SDL3 initialized successfully. Close the window to exit.");

    bool running{true};
    int exit_code{EXIT_SUCCESS};

    while (running) {
        SDL_Event event{};
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        if (!running) {
            break;
        }

        if (!SDL_SetRenderDrawColor(
                renderer,
                background_red,
                background_green,
                background_blue,
                background_alpha
            ) ||
            !SDL_RenderClear(renderer) ||
            !SDL_RenderPresent(renderer)) {
            SDL_LogError(
                SDL_LOG_CATEGORY_APPLICATION,
                "Could not render the frame: %s",
                SDL_GetError()
            );
            exit_code = EXIT_FAILURE;
            running = false;
        }

        if (!vsync_enabled) {
            SDL_Delay(16);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return exit_code;
}
