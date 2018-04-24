#include "Texture.hpp"

namespace Coronet
{
    void Texture::Draw(SDL_Renderer *renderer)
    {
        SDL_Texture *texture = GetDrawTexture();
        Vector2 size = GetDrawSize();
        Vector2 position = GetDrawPosition();

        SDL_Rect dest = { position.x, position.y, size.x, size.y };
        SDL_RenderCopy(renderer, texture, NULL, &dest);
    }
}