#pragma once

#include <SDL2/SDL.h>

namespace Coronet
{
    // todo: move into BaseClock class with SettableClock and SDLClock classes
    class Clock
    {
        private:
            Uint32 ticks = 0;
            Uint32 ticksStarted = 0;
            Uint32 ticksPaused = 0;
            bool started = false;
            bool paused = false;

        public:
            Clock();
            ~Clock();
            void SetTicks(Uint32 ticks);
            Uint32 GetTicks();
            bool IsStarted();
            bool IsPaused();
            void Start();
            void Stop();
            void Pause();
            void Unpause();
    };
}
