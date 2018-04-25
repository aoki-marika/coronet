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
            position = position - camera->Position;

        if (!Parent.expired())
            position = Parent.lock()->GetDrawPosition() + position;

        return position;
    }

    Vector2 Drawable::GetDrawSize()
    {
        return { 0, 0 };
    }

    Visibility Drawable::GetVisibility()
    {
        if (Visibility != Visibility::Hidden && !Parent.expired())
            return Parent.lock()->GetVisibility();

        return Visibility;
    }

    bool Drawable::IsVisible()
    {
        if (GetVisibility() == Visibility::Hidden)
            return false;

        Vector2 p = GetDrawPosition(true);
        Vector2 s = GetDrawSize();
        SDL_Rect v = camera->GetViewport();

        // ignore camera position if we are in screen space
        if (Space == DrawablePositionSpace::Screen)
        {
            v.x = 0;
            v.y = 0;
        }

        bool offScreen = p.x >= v.w || p.x + s.x <= 0 ||
                         p.y >= v.h || p.y + s.y <= 0;

        return !offScreen;
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