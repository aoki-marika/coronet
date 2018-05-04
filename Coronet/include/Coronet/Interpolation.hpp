#pragma once

#include "Easing.hpp"

namespace Coronet
{
    class Interpolation
    {
        public:
            static double ValueAt(double time, double startValue, double endValue, double startTime, double endTime, Easing easing);
            static double ApplyEasing(Easing easing, double time);
    };
}