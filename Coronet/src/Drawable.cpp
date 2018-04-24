#include "Drawable.hpp"

namespace Coronet
{
    Drawable::Drawable()
    {
    }

    Drawable::~Drawable()
    {
    }

    void Drawable::Load(DependencyManager &dependencies)
    {
    }

    void Drawable::LoadComplete()
    {
    }

    void Drawable::Inject(DependencyManager &dependencies, bool callComplete)
    {
        if (State == DrawableLoadState::Unloaded)
        {
            Load(dependencies);
            State = DrawableLoadState::Loaded;

            if (callComplete)
                LoadComplete();
        }
    }

    void Drawable::Update()
    {
    }

    void Drawable::Draw()
    {
    }
}