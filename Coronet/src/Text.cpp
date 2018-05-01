#include "Text.hpp"

namespace Coronet
{
    Text::Text(const std::shared_ptr<Font> &font)
    {
        this->font = font;
        this->colour = { 255, 255, 255 };
    }

    void Text::SetText(std::string text)
    {
        this->text = text;

        SetBitmap(font->GetTextBitmap(text, colour));
    }

    void Text::SetColour(SDL_Colour colour)
    {
        this->colour = colour;

        // update the text colour
        SetText(text);
    }
}