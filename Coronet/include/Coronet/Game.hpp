#pragma once

#include "Container.hpp"

namespace Coronet
{
    class Game : public Container
    {
        public:
            Game();

            virtual void OnRun();
            virtual void OnExit();
    };
}