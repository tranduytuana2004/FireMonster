#include "TextObject.h"
#include <SDL_ttf.h>

TextObject::TextObject()
{
    rect.x = SCREEN_WIDTH - 100;
    rect.y = 5;
    text_color.r = 255;
    text_color.g = 255;
    text_color.b = 255;
}

TextObject::~TextObject()
{
    ;
}

void TextObject::initText(TTF_Font*& fontText)
{
    fontText = TTF_OpenFont("font\\Minecraft.ttf",72);
    if(fontText == NULL)
    {
        cout << "Font Error" << endl;
    }
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

void TextObject::CreateGameText(TTF_Font* font, SDL_Renderer* renderer,int w, int h)
{
	textSurface = TTF_RenderText_Solid(font, str.c_str(), text_color);
	body = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_Rect des = {rect.x,rect.y,w,h};
    SDL_RenderCopy(renderer,body,nullptr,&des);
}
