#ifndef PLANE_H
#define PLANE_H

#include "Object.h"
#include "Bullet.h"

class Plane : public Object
{
private :
    int x;
    int y;
    vector<Bullet> list_bullets;
    Bullet bullet;
public :
    bool isShot;

    int hp = HP_DEFAULT;

    Plane();

    Plane(SDL_Renderer* renderer);

    void move(SDL_Event event);

    void update(SDL_Renderer* renderer);

    SDL_Rect getRectBullet();

    vector<Bullet> getListBullets()
    {
        return list_bullets;
    }

    ~Plane();
};

#endif // PLANE_H
