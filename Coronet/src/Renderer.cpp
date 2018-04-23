#include "Renderer.hpp"
#include "Utilities.hpp"

namespace Coronet
{
    Renderer::Renderer(const std::shared_ptr<Window> &window)
    {
        renderer = SDL_CreateRenderer(window->GetWindow(), -1, SDL_RENDERER_ACCELERATED);
        if (renderer == NULL)
            ThrowSDLException("CreateRenderer");
    }

    Renderer::~Renderer()
    {
        SDL_DestroyRenderer(renderer);
    }
}