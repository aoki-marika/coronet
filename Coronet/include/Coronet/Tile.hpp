#pragma once

#include "Vector2.hpp"

namespace Coronet
{
    //todo: to struct
    class Tile
    {
        protected:
            Vector2 sheetPosition;

        public:
            Tile(int x, int y);
            Tile();

            Vector2 GetSheetPosition();
    };
}
