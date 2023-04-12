#include "Bullet.h"
#include "Object.h"

Bullet::Bullet()
{
    x = 0;
    y = 0;
    isMove = false;
}

void Bullet::plane_fire()
{
    if( rect.y < -rect.h )
    {
        isMove = false;
    }
    rect.y -= SPEED_BULLET_PLANE;
}

void Bullet::enemy_fire()
{
    if( rect.y > SCREEN_HEIGHT )
    {
        isMove = false;
    }
    rect.y += SPEED_BULLET_ENEMY;
}

void Bullet::setStatus(bool _isMove)
{
    this -> isMove = _isMove;
}

Bullet::~Bullet()
{

}

void Bullet::icon_move()
{
    if( rect.y > SCREEN_HEIGHT*3 )
    {
        rect.x = rand() % (SCREEN_WIDTH - 20 - 10) + 1;
        rect.y = 0;
    }
    rect.y++;
}
