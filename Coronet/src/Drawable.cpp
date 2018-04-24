#include "Drawable.hpp"

namespace Coronet
{
    Drawable::Drawable()
    {
    }

    Drawable::~Drawable()
    {
    }

    Vector2 Drawable::GetDrawPosition()
    {
        if (!Parent.expired())
        {
            Vector2 parentPosition = Parent.lock()->GetDrawPosition();
            return { parentPosition.x + Position.x, parentPosition.y + Position.y };
        }

        return Position;
    }

    void Drawable::Load(DependencyManager &dependencies)
    {
        clock = dependencies.Get<GameClock>();
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
        UpdateTransforms(clock);
    }

    void Drawable::Draw(SDL_Renderer *renderer)
    {
    }
}