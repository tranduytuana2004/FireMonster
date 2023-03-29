#ifndef TEXTOBJECT_H
#define TEXTOBJECT_H

#include "Object.h"
#include <SDL_ttf.h>

class TextObject : public Object
{
private:
    string str;
    SDL_Color text_color;
    SDL_Surface* textSurface;

public:
    enum TextColor
    {
        RED_TEXT = 0,
        WHITE_TEXT = 1,
        BLACK_TEXT = 2,

    };
    TextObject();
    ~TextObject();

    void initText(TTF_Font*& fontText);

    void SetText(const string& text)
    {
        str = text;
    }
    void SetColor(const int& type);

    void CreateGameText(TTF_Font* font, SDL_Renderer* renderer,int x, int y);
};
#endif // TEXTOBJECT_H
