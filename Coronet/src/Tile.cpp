#include "Tile.hpp"

namespace Coronet
{
    Tile::Tile(int x, int y)
    {
        this->sheetPosition = { x, y };
    }

    Tile::Tile()
    {
        this->sheetPosition = { -1, -1 };
    }

    Vector2 Tile::GetSheetPosition()
    {
        return sheetPosition;
    }
}
