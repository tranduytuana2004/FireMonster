#include "Enemy.h"

Enemy::Enemy(SDL_Renderer* renderer, int i)
{
    alive = true;
    x = 0;
    y = 0;
    rect.w = 80;
    rect.h = 80;
    setPos(x,y);
    setImg(renderer, "D:\\Code\\banga\\FireMonster\\image\\enemy" + to_string(i) + ".png");
}

void Enemy::move(SDL_Event event)
{

}

void Enemy::update(SDL_Renderer* renderer)
{
    if( alive )
    {
        rect.y++;
        show(renderer);
    }
}
