#include <SDL2/SDL_image.h>

#include "Vector2.hpp"

namespace Coronet
{
    class Bitmap
    {
        private:
            Vector2 size;
            SDL_Surface *surface = NULL;

        public:
            Bitmap(const char *path);
            ~Bitmap();

            Vector2 GetSize();
    };
}