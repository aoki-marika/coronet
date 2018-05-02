#pragma once

#include <memory>
#include <SDL2/SDL.h>

namespace Coronet
{
    template<class T> class AssetFile
    {
        private:
            char *buffer;
            SDL_RWops *rw;
            std::shared_ptr<T> asset;

        protected:
            SDL_RWops *GetRWops()
            {
                return rw;
            }

            virtual std::shared_ptr<T> CreateAsset() = 0;

        public:
            AssetFile(char *buffer, int length)
            {
                this->buffer = buffer;
                rw = SDL_RWFromMem(buffer, length);
            }

            ~AssetFile()
            {
                SDL_RWclose(rw);
                delete buffer;
            }

            std::shared_ptr<T> GetAsset()
            {
                if (asset == nullptr)
                    asset = CreateAsset();

                return asset;
            }
    };
}