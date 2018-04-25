#pragma once

#include "Container.hpp"

namespace Coronet
{
    class Game : public Container
    {
        public:
            virtual void OnRun();
            virtual void OnExit();
    };
}