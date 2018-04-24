#include "Texture.hpp"

namespace Coronet
{
    void Texture::Draw(SDL_Renderer *renderer)
    {
        SDL_Texture *texture = GetDrawTexture();
        Vector2 size = GetDrawSize();

        SDL_Rect dest = { 0, 0, size.x, size.y };
        SDL_RenderCopy(renderer, texture, NULL, &dest);
    }
}