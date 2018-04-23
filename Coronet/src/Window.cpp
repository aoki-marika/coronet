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
    }

    Window::~Window()
    {
        SDL_DestroyWindow(window);
    }

    SDL_Window *Window::GetWindow()
    {
        return window;
    }
}