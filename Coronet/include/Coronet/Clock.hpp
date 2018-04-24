#pragma once

#include <SDL2/SDL.h>

namespace Coronet
{
    class Clock
    {
        private:
            Uint32 ticksStarted = 0;
            Uint32 ticksPaused = 0;
            Uint32 lastTicks = 0;
            bool started = false;
            bool paused = false;

        protected:
            virtual Uint32 GetCurrentTicks() = 0;

        public:
            Clock();
            ~Clock();
            Uint32 GetTicks(); // the ticks since the clock was started
            Uint32 GetElapsed(); // the ticks since the last clock update
            bool IsStarted();
            bool IsPaused();
            void Start();
            void Stop();
            void Pause();
            void Unpause();
            void Update();
    };
}
