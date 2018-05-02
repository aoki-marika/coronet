#include "AssetFile.hpp"
#include "Bitmap.hpp"

namespace Coronet
{
    class AssetBitmap : public AssetFile<Bitmap>
    {
        protected:
            std::shared_ptr<Bitmap> CreateAsset() override;

        public:
            AssetBitmap(char *buffer, int length);
    };
}