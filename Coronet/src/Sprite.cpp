#include "Sprite.hpp"

namespace Coronet
{
    Sprite::Sprite(const std::shared_ptr<Bitmap> &bitmap) : bitmap(bitmap)
    {
        // texture = bitmap->ToTexture();
    }

    Sprite::~Sprite()
    {
        if (texture != NULL)
            SDL_DestroyTexture(texture);
    }

    SDL_Texture *Sprite::GetDrawTexture()
    {
        return texture;
    }

    Vector2 Sprite::GetDrawSize()
    {
        return bitmap->GetSize();
    }
}