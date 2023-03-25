#include "TextObject.h"
#include <SDL_ttf.h>

TextObject::TextObject()
{
    ;
}

TextObject::~TextObject()
{
    ;
}

void TextObject::SetColor(const int& type)
{
    if(type == RED_TEXT)
    {
        SDL_Color color = {255,0,0};
        text_color = color;
    }
    else if(type == WHITE_TEXT)
    {
        SDL_Color color = {255,255,255};
        text_color = color;
    }
    else
    {
        SDL_Color color = {0,0,0};
        text_color = color;
    }
}

void TextObject::CreateGameText(TTF_Font* font, SDL_Renderer* renderer)
{
	textSurface = TTF_RenderText_Solid(font, str.c_str(), text_color);
	body = SDL_CreateTextureFromSurface(renderer, textSurface);
	show(renderer);
}
