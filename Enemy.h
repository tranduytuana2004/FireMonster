#ifndef ENEMY_H
#define ENEMY_H

#include "Object.h"
#include "Bullet.h"

class Enemy : public Object
{
private:
    int x;
    int y;
    Bullet bullet;
    bool alive;
public:
    Enemy(SDL_Renderer* renderer, int i);

    ~Enemy()
    {

    }

    void move(SDL_Event event);

    void update(SDL_Renderer* renderer);

    void kill()
    {
        alive = false;
    }

    bool isKilled()
    {
        return !alive;
    }
};
#endif // ENEMY_H
