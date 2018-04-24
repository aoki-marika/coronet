#include "Drawable.hpp"
#include "Bitmap.hpp"

namespace Coronet
{
    class Sprite : public Drawable
    {
        private:
            Bitmap bitmap;

        public:
            Sprite(Bitmap bitmap);
    };
}