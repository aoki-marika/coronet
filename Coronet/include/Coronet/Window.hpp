#include <SDL2/SDL.h>

namespace Coronet
{
    class Window
    {
        private:
            SDL_Window *window;

        public:
            Window(int x, int y, int width, int height, const char *title = "Window");
            ~Window();
    };
}