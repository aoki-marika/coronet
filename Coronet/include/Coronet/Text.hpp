#include <string>

#include "Font.hpp"
#include "Sprite.hpp"

namespace Coronet
{
    class Text : public Sprite
    {
        private:
            std::shared_ptr<Font> font;
            std::string text;
            SDL_Colour colour; //defaults to white

        public:
            Text(const std::shared_ptr<Font> &font);
            Text(const std::shared_ptr<Font> &font, std::string text);
            Text(const std::shared_ptr<Font> &font, SDL_Colour colour);
            Text(const std::shared_ptr<Font> &font, std::string text, SDL_Colour colour);

            void SetText(std::string text);
            void SetColour(SDL_Colour colour);
    };
}