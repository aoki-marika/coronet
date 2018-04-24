namespace Coronet
{
    // more easing types are most likely not going to be added, but
    // this is designed to allow them to be if needed
    enum class Easing
    {
        None,
        In,
        Out
    };

    class Interpolation
    {
        public:
            static double ValueAt(double time, double startValue, double endValue, double startTime, double endTime, Easing easing);
            static double ApplyEasing(Easing easing, double time);
    };
}