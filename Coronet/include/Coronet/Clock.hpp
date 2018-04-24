#pragma once

#include <SDL2/SDL.h>

namespace Coronet
{
    class Clock
    {
        private:
            Uint32 ticksStarted = 0;
            Uint32 ticksPaused = 0;
            bool started = false;
            bool paused = false;

        protected:
            virtual Uint32 GetCurrentTicks() = 0;

        public:
            Clock();
            ~Clock();
            Uint32 GetTicks();
            bool IsStarted();
            bool IsPaused();
            void Start();
            void Stop();
            void Pause();
            void Unpause();
    };
}
