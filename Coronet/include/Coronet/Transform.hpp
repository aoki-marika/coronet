#include <functional>

#include "Clock.hpp"
#include "Interpolation.hpp"

namespace Coronet
{
    class Transform
    {
        private:
            double startValue, endValue, startTime, endTime;
            Easing easing;
            std::function<void(double)> callback;
            std::function<void()> onFinished;
            bool isStarted = false;
            bool isFinished = false;

        public:
            Transform(double startValue, double endValue, double startTime, double endTime, Easing easing, std::function<void(double)> callback, std::function<void()> onFinished = nullptr);

            void Update(const std::shared_ptr<Clock> &clock);
            bool IsFinished();
            bool operator==(const Transform &other);
    };
}