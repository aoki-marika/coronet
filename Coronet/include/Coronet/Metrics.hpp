#include "Vector2.hpp"

namespace Coronet
{
    class Metrics
    {
        private:
            Vector2 tileSize;
            Vector2 tileCount;
            Vector2 blockSize;
            Vector2 screenSize;

        public:
            Metrics(int tileWidth, int tileHeight, int blockTilesHorizontal, int blockTilesVertical, int screenTilesHorizontal, int screenTilesVertical);

            Vector2 GetTileSize(); // the size of each tile in pixels
            Vector2 GetTileCount(); // the amount of tiles that are displayed on screen
            Vector2 GetBlockSize(); // the size of each block in pixels
            Vector2 GetScreenSize(); // the size of the screen in pixels
    };
}