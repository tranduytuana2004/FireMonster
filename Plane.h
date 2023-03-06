#ifndef PLANE_H
#define PLANE_H

#include "Object.h"
#include "Bullet.h"

class Plane : public Object
{
private :
    int x;
    int y;
    Bullet bullet;

public :
    Plane();

    Plane(SDL_Renderer* renderer, string path);

    void move(SDL_Event event);

    void update(SDL_Renderer* renderer);

    SDL_Rect getRectBullet();

    Bullet getBullet()
    {
        return bullet;
    }

    ~Plane();
};

#endif // PLANE_H
