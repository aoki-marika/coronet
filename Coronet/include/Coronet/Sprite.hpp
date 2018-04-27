#pragma once

#include "Texture.hpp"
#include "Bitmap.hpp"

namespace Coronet
{
    class Sprite : public Texture
    {
        private:
            std::shared_ptr<Bitmap> bitmap;
            SDL_Renderer *renderer = nullptr;
            SDL_Texture *texture = nullptr;

        protected:
            SDL_Texture *GetDrawTexture() override;
            Vector2 GetDrawSize() override;

            virtual void Load(DependencyManager &dependencies) override;

        public:
            Sprite(const std::shared_ptr<Bitmap> &bitmap);
            Sprite();
            ~Sprite();

            void SetBitmap(const std::shared_ptr<Bitmap> &bitmap);
    };
}