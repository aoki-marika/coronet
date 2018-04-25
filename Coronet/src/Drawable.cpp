#include "Drawable.hpp"

namespace Coronet
{
    Drawable::Drawable()
    {
    }

    Drawable::~Drawable()
    {
    }

    Vector2 Drawable::GetDrawPosition(bool includeCamera)
    {
        Vector2 position = Position;

        if (includeCamera && Space == DrawablePositionSpace::World)
            position = camera->Position + position;

        if (!Parent.expired())
            position = Parent.lock()->GetDrawPosition() + position;

        return position;
    }

    Vector2 Drawable::GetDrawSize()
    {
        return { 0, 0 };
    }

    bool Drawable::IsVisible()
    {
        Vector2 p = GetDrawPosition();
        Vector2 s = GetDrawSize();
        SDL_Rect v = camera->GetViewport();

        return p.x < v.x + v.w ||
               p.y < v.y + v.h ||
               p.x + s.x < v.x ||
               p.y + s.y < v.y;
    }

    void Drawable::Load(DependencyManager &dependencies)
    {
        clock = dependencies.Get<GameClock>();
        camera = dependencies.Get<Camera>();
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