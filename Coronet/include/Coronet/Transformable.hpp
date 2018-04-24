#include <vector>

#include "Transform.hpp"
#include "Clock.hpp"

namespace Coronet
{
    class Transformable
    {
        private:
            std::vector<Transform> transforms;

        public:
            void AddTransform(Transform transform);
            void UpdateTransforms(const std::shared_ptr<Clock> &clock);
    };
}