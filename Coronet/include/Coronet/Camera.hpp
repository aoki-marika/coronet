#pragma once

#import <SDL2/SDL.h>

#include "Vector2.hpp"

namespace Coronet
{
    class Camera
    {
        private:
            Vector2 size;

        public:
            // X: -left +right
            // Y: -up +down
            Vector2 Position = { 0, 0 };

            Camera(int viewportWidth, int viewportHeight);
            SDL_Rect GetViewport();
    };
}
