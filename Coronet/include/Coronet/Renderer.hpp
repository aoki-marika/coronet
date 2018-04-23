#include <SDL2/SDL.h>

#include "Container.hpp"
#include "Window.hpp"

namespace Coronet
{
    class Renderer : public Container
    {
        private:
            SDL_Renderer *renderer;

        public:
            Renderer(const std::shared_ptr<Window> &window);
            ~Renderer();

            void Update() override;
    };
}