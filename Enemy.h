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

    void kill();

    SDL_Rect getRectBullet();

    bool isKilled();

    void clear_bullet();
};
#endif // ENEMY_H
