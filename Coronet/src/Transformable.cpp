#include "Transformable.hpp"

namespace Coronet
{
    void Transformable::AddTransform(Transform transform)
    {
        transforms.push_back(transform);
    }

    void Transformable::UpdateTransforms(const std::shared_ptr<Clock> &clock)
    {
        for (auto &t : transforms)
        {
            if (!t.IsFinished())
                t.Update(clock);
            else
                transforms.erase(std::remove(transforms.begin(), transforms.end(), t), transforms.end());
        }
    }
}