#ifndef BULLET_H
#define BULLET_H

#include "Object.h"

class Bullet : public Object
{
private:
    int x;
    int y;
    bool isMove;

public:

    Bullet();

    void setrect(int a, int b)
    {
        rect.x = a;
        rect.y = b;
    }

    void plane_fire();

    void enemy_fire(int score,double direc);

    void icon_move();

    void setStatus(bool _isMove);

    bool is_Move()
    {
        return isMove;
    }
    ~Bullet();
};
#endif // BULLET_H
