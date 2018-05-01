#include <string>

#include "AssetFile.hpp"

namespace Coronet
{
    class AssetStore
    {
        private:
            void throwPhysfsException(std::string message);

        public:
            AssetStore();
            ~AssetStore();

            void Mount(const char *path);
            AssetFile Read(const char *path);
    };
}