#include "Transform.hpp"

namespace Coronet
{
    Transform::Transform(double startValue, double endValue, double startTime, double endTime, Easing easing, std::function<void(double)> callback, std::function<void()> onFinished)
    {
        this->startValue = startValue;
        this->endValue = endValue;
        this->startTime = startTime;
        this->endTime = endTime;
        this->easing = easing;
        this->callback = callback;
        this->onFinished = onFinished;
    }

    Transform::~Transform()
    {
    }

    void Transform::Update(const std::shared_ptr<Clock> &clock)
    {
        Uint32 ticks = clock->GetTicks();

        if (ticks >= startTime && ticks <= endTime)
        {
            isStarted = true;

            double value = Interpolation::ValueAt(ticks, startValue, endValue, startTime, endTime, easing);
            callback(value);
        }
        else if (isStarted && !isFinished)
        {
            if (onFinished != nullptr)
                onFinished();

            isStarted = false;
            isFinished = true;
        }
    }

    bool Transform::IsFinished()
    {
        return isFinished;
    }

    bool Transform::operator==(const Transform &other) {
        return startValue == other.startValue &&
               endValue == other.endValue &&
               startTime == other.startTime &&
               endTime == other.endTime &&
               easing == other.easing;
    }
}
