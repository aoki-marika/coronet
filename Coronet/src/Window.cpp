#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Window.hpp"
#include "Utilities.hpp"

namespace Coronet
{
    Window::Window(int x, int y, int width, int height, const char *title)
    {
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
            ThrowSDLException("Init");

        window = SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_SHOWN);
        if (window == NULL)
            ThrowSDLException("CreateWindow");

        if (TTF_Init() != 0)
            ThrowTTFException("Init");
    }

    Window::~Window()
    {
        SDL_DestroyWindow(window);
        QuitSDL();
    }

    SDL_Window *Window::GetWindow()
    {
        return window;
    }
}