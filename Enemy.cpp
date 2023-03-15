#include "Enemy.h"

Enemy::Enemy(SDL_Renderer* renderer, int i)
{
    alive = true;

    x = 0;
    y = 0;

    rect.w = WIDTH_ENEMY;

    rect.h = HEIGHT_ENEMY;

    setPos(x,y);

    setImg(renderer, "D:\\Code\\banga\\FireMonster\\image\\enemy" + to_string(i) + ".png");

    list_bullets.setImg(renderer, "D:\\Code\\banga\\FireMonster\\image\\bulletenemy" + to_string(i) + ".png");

    list_bullets.setSize(WIDTH_BULLET_ENEMY,HEIGHT_BULLET_ENEMY);
}

void Enemy::kill()
{
    alive = false;
}

SDL_Rect Enemy::getRectBullet()
{
    return list_bullets.getRect();
}
void Enemy::update(SDL_Renderer* renderer)
{
    if( !list_bullets.is_Move())
        {
            list_bullets.setStatus(true);

            list_bullets.setPos(rect.x + rect.w/2, rect.y +15);
        }

    if( alive )
    {
        rect.y ++; //Cho enemy chạy xuống

        if( list_bullets.is_Move())
        {
            list_bullets.enemy_fire();

            list_bullets.show(renderer);
        }

        // Enemy chạy lại từ trên xuống ngẫu nhiễn
        if( rect.y > SCREEN_HEIGHT )
        {
            rect.x = rand() % (SCREEN_WIDTH - rect.w);

            if (rect.x < rect.w)
            {
                rect.x = rect.w;
            }

            rect.y = 0; // Enemy chạy lại từ trên xuống
        }

        show(renderer);
    }
}

void Enemy::clear_bullet()
{
    list_bullets.setPos(0,0);
    list_bullets.setStatus(false);
}

bool Enemy::isKilled()
{
    return !alive;
}
