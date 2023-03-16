#ifndef PLANE_H
#define PLANE_H

#include "Object.h"
#include "Bullet.h"

class Plane : public Object
{
private :
    int x;
    int y;
    Bullet list_bullets;
    bool alive;
public :
    int hp = HP_DEFAULT;

    Plane();

    Plane(SDL_Renderer* renderer);

    void move(SDL_Event event);

    void update(SDL_Renderer* renderer);

    SDL_Rect getRectBullet();

    void clear_bullet();

    bool get_alive() const {return alive;}

    ~Plane();
};

#endif // PLANE_H
