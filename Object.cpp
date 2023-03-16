#include "Object.h"
#include "Boardgame.h"

Object::Object()
{
    rect.x = 10;
    rect.y = 10;
    rect.w = 85;
    rect.h = 51;
    body = nullptr;
}

Object::Object(SDL_Renderer* renderer, string path)
{
    rect.x = 10;
    rect.y = 10;
    rect.w = 100;
    rect.h = 100;
    body = BG::loadTexture(renderer,path);
}

Object::~Object()
{

}

void Object::show(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, body, NULL, &rect);
}

void Object::setImg(SDL_Renderer* renderer, string path)
{
    body = BG::loadTexture(renderer,path);
}
void Object::setPos(int _x, int _y)
{
    rect.x = _x;
    rect.y = _y;
}

void Object::setSize(int _w, int _h)
{
    rect.w = _w;
    rect.h = _h;
}
