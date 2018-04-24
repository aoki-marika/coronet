#include "GameClock.hpp"

namespace Coronet
{
    Uint32 GameClock::GetCurrentTicks()
    {
        return ticks;
    }

    void GameClock::SetTicks(Uint32 ticks)
    {
        this->ticks = ticks;
    }
}