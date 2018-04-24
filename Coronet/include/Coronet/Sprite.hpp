#include "Drawable.hpp"
#include "Bitmap.hpp"

namespace Coronet
{
    class Sprite : public Drawable
    {
        private:
            std::shared_ptr<Bitmap> bitmap;

        public:
            Sprite(const std::shared_ptr<Bitmap> &bitmap);
    };
}