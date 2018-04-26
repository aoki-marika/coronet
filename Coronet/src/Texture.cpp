#include "Texture.hpp"

namespace Coronet
{
    void Texture::Draw(SDL_Renderer *renderer)
    {
        SDL_Texture *texture = GetDrawTexture();

        if (IsVisible() && texture != nullptr)
        {
            Vector2 size = GetDrawSize();
            Vector2 position = GetDrawPosition(true);
            SDL_RendererFlip flip = (SDL_RendererFlip)GetFlip();

            SDL_Rect dest = { position.x, position.y, size.x, size.y };

            SDL_RenderCopyEx(renderer, texture, NULL, &dest, 0, NULL, flip);
        }
    }
}