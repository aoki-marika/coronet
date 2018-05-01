#include <SDL2/SDL.h>

namespace Coronet
{
    class AssetFile
    {
        private:
            char *buffer;
            SDL_RWops *rw;

        public:
            AssetFile(char *buffer, int length);
            ~AssetFile();

            SDL_RWops *GetRWops();
    };
}