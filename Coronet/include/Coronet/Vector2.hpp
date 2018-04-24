#pragma once

namespace Coronet
{
    struct Vector2
    {
        int x;
        int y;

        const Vector2 operator+(const Vector2 &rhs)
        {
            return { x + rhs.x, y + rhs.y };
        }
    };
}