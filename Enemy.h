#ifndef ENEMY_H
#define ENEMY_H

#include "Object.h"
#include "Bullet.h"

class Enemy : public Object
{
private:
    int x;
    int y;
    Bullet list_bullets;
    bool alive;
public:
    Enemy(SDL_Renderer* renderer, int i);

    ~Enemy()
    {

    }

    void update(SDL_Renderer* renderer);

    void kill()
    {
        alive = false;
    }

    SDL_Rect getRectBullet()
    {
        return list_bullets.getRect();
    }

    bool isKilled()
    {
        return !alive;
    }
};
#endif // ENEMY_H
