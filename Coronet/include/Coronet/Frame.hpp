namespace Coronet
{
    template<class T> class Frame
    {
        private:
            T content;
            double duration;

        public:
            Frame(T content, double duration) : content(content)
            {
                this->duration = duration;
            }

            T &GetContent()
            {
                return content;
            }

            double GetDuration()
            {
                return duration;
            }
    };
}