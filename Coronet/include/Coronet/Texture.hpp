#include <SDL2/SDL.h>

#include "Drawable.hpp"
#include "Vector2.hpp"

namespace Coronet
{
    class Texture : public Drawable
    {
        protected:
            virtual SDL_Texture *GetDrawTexture() = 0;
            virtual Vector2 GetDrawSize() = 0;

        public:
            void Draw(SDL_Renderer *renderer) override;
    };
}