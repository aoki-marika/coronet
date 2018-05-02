#include <iostream>
#include <SDL2/SDL_ttf.h>

#include "AssetFile.hpp"
#include "TTFFont.hpp"

namespace Coronet
{
    class AssetTTFFont : public AssetFile<TTFFont>
    {
        private:
            int ptsize;

        protected:
            std::shared_ptr<TTFFont> CreateAsset() override
            {
                return std::make_shared<TTFFont>(TTF_OpenFontRW(GetRWops(), 0, ptsize));
            }

        public:
            AssetTTFFont(char *buffer, int length, int ptsize) : AssetFile(buffer, length)
            {
                this->ptsize = ptsize;
            }
    };
}