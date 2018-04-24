#pragma once

#include "Clock.hpp"

namespace Coronet
{
    class GameClock : public Clock
    {
        private:
            Uint32 ticks;

        protected:
            Uint32 GetCurrentTicks() override;

        public:
            void SetTicks(Uint32 ticks);
    };
}
