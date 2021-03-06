#include "Camera.hpp"

namespace Coronet
{
    Camera::Camera(int viewportWidth, int viewportHeight)
    {
        size = { viewportWidth, viewportHeight };
    }

    SDL_Rect Camera::GetViewport()
    {
        return { Position.x, Position.y, size.x, size.y };
    }
}
