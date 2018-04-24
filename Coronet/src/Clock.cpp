#include <stdexcept>

#include "Clock.hpp"

namespace Coronet
{
    Clock::Clock()
    {
    }

    Clock::~Clock()
    {
        if (paused)
            Unpause();

        if (started)
            Stop();
    }

    void Clock::SetTicks(Uint32 ticks)
    {
        this->ticks = ticks;
    }

    Uint32 Clock::GetTicks()
    {
        Uint32 ticks = 0;

        if (started)
        {
            if (paused)
                ticks = ticksPaused;
            else
                ticks = this->ticks - ticksStarted;
        }

        return ticks;
    }

    bool Clock::IsStarted()
    {
        return started;
    }

    bool Clock::IsPaused()
    {
        return paused;
    }

    void Clock::Start()
    {
        if (!started)
        {
            if (!paused)
            {
                started = true;

                ticksStarted = ticks;
                ticksPaused = 0;
            }
            else
                throw std::logic_error("Cannot start a paused Clock.");
        }
        else
            throw std::logic_error("Cannot start an already started Clock.");
    }

    void Clock::Stop()
    {
        if (started)
        {
            started = false;

            ticksStarted = 0;
            ticksPaused = 0;
        }
        else
            throw std::logic_error("Cannot stop an unstarted Clock.");
    }

    void Clock::Pause()
    {
        if (started)
        {
            if (!paused)
            {
                paused = true;

                ticksPaused = ticks - ticksStarted;
                ticksStarted = 0;
            }
            else
                throw std::logic_error("Cannot pause an already paused Clock.");
        }
        else
            throw std::logic_error("Cannot pause an unstarted Clock.");
    }

    void Clock::Unpause()
    {
        if (started)
        {
            if (paused)
            {
                paused = false;

                ticksStarted = ticks - ticksPaused;
                ticksPaused = 0;
            }
            else
                throw std::logic_error("Cannot unpause an already unpaused clock.");
        }
        else
            throw std::logic_error("Cannot unpause an unstarted Clock.");
    }
}
