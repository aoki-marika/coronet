#include "Texture.hpp"
#include "Bitmap.hpp"

namespace Coronet
{
    class Sprite : public Texture
    {
        private:
            std::shared_ptr<Bitmap> bitmap;
            SDL_Texture *texture = NULL;

        protected:
            SDL_Texture *GetDrawTexture() override;
            Vector2 GetDrawSize() override;

        public:
            Sprite(const std::shared_ptr<Bitmap> &bitmap);
            ~Sprite();
    };
}