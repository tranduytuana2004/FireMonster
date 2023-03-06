#include "Bullet.h"
#include "Object.h"

Bullet::Bullet()
{
    x = 0;
    y = 0;
    isMove = false;
    speed = 20;
    rect.w = 15;
    rect.h = 50;
}

void Bullet::fire()
{
    if( rect.y < -rect.h )
    {
        isMove = false;
    }
    rect.y -= speed;
}

void Bullet::setStatus(bool _isMove)
{
    this -> isMove = _isMove;
}

Bullet::~Bullet()
{

}
