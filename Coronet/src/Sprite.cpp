#include "Sprite.hpp"
#include "Renderer.hpp"

namespace Coronet
{
    // todo: allow setting the bitmap after the ctor
    Sprite::Sprite(const std::shared_ptr<Bitmap> &bitmap) : bitmap(bitmap)
    {
    }

    Sprite::~Sprite()
    {
        if (texture != NULL)
            SDL_DestroyTexture(texture);
    }

    void Sprite::Load(DependencyManager &dependencies)
    {
        Texture::Load(dependencies);

        texture = bitmap->ToTexture(dependencies.Get<Renderer>()->GetRenderer());
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