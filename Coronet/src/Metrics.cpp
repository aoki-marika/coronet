#include "Metrics.hpp"

namespace Coronet
{
    Metrics::Metrics(int tileWidth, int tileHeight, int blockTilesHorizontal, int blockTilesVertical, int screenTilesHorizontal, int screenTilesVertical)
    {
        tileSize = { tileWidth, tileHeight };
        tileCount = { screenTilesHorizontal, screenTilesVertical };
        blockSize = { tileWidth * blockTilesHorizontal, tileHeight * blockTilesVertical };
        screenSize = { tileWidth * screenTilesHorizontal, tileHeight * screenTilesVertical };
    }

    Vector2 Metrics::GetTileSize()
    {
        return tileSize;
    }

    Vector2 Metrics::GetTileCount()
    {
        return tileCount;
    }

    Vector2 Metrics::GetBlockSize()
    {
        return blockSize;
    }

    Vector2 Metrics::GetScreenSize()
    {
        return screenSize;
    }
}