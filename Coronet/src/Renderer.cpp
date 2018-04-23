#include "Renderer.hpp"
#include "Utilities.hpp"

namespace Coronet
{
    Renderer::Renderer(const std::shared_ptr<Window> &window)
    {
        renderer = SDL_CreateRenderer(window->GetWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer == NULL)
            ThrowSDLException("CreateRenderer");
    }

    Renderer::~Renderer()
    {
        SDL_DestroyRenderer(renderer);
    }

    void Renderer::Update()
    {
        Container::Update();
    }

    void Renderer::Draw()
    {
        SDL_RenderClear(renderer);

        Container::Draw();

        SDL_RenderPresent(renderer);
    }
}