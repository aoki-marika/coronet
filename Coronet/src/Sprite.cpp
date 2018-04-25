#include "Sprite.hpp"
#include "Renderer.hpp"

namespace Coronet
{
    Sprite::Sprite(const std::shared_ptr<Bitmap> &bitmap)
    {
        SetBitmap(bitmap);
    }

    Sprite::Sprite()
    {
    }

    Sprite::~Sprite()
    {
        if (texture != nullptr)
            SDL_DestroyTexture(texture);
    }

    void Sprite::Load(DependencyManager &dependencies)
    {
        Texture::Load(dependencies);

        renderer = dependencies.Get<Renderer>()->GetRenderer();

        if (bitmap != nullptr)
            texture = bitmap->ToTexture(renderer);
    }

    SDL_Texture *Sprite::GetDrawTexture()
    {
        return texture;
    }

    Vector2 Sprite::GetDrawSize()
    {
        if (bitmap != nullptr)
            return bitmap->GetSize();
        else
            return { 0, 0 };
    }

    void Sprite::SetBitmap(const std::shared_ptr<Bitmap> &bitmap)
    {
        if (this->bitmap == bitmap) return;
        this->bitmap = bitmap;

        if (renderer != nullptr)
            texture = bitmap->ToTexture(renderer);
    }
}