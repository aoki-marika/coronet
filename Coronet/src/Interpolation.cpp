#import "Interpolation.hpp"

namespace Coronet
{
    double Interpolation::ValueAt(double time, double startValue, double endValue, double startTime, double endTime, Easing easing)
    {
        double t = ApplyEasing(easing, (time - startTime) / (endTime - startTime));
        return startValue + t * (endValue - startValue);
    }

    double Interpolation::ApplyEasing(Easing easing, double time)
    {
        switch (easing)
        {
            case Easing::In:
                return time * time;
            case Easing::Out:
                return time * (2 - time);
            default:
                return time;
        }
    }
}