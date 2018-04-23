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

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
}