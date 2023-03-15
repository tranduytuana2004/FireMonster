#ifndef OBJECT_H
#define OBJECT_H

#include "Boardgame.h"

class Object
{
protected:
    SDL_Rect rect;
    SDL_Texture* body;
public:
    Object();

    Object(SDL_Renderer* renderer, string path);

    ~Object();

    void show(SDL_Renderer* renderer);

    void setImg(SDL_Renderer* renderer, string path);

    void setPos(int _x, int _y);

    void setSize(int _w, int _h);

    SDL_Rect getRect() const
    {
        return rect;
    }
    void Free();
};
#endif // OBJECT_H
