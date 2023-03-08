#ifndef BULLET_H
#define BULLET_H

#include "Object.h"

class Bullet : public Object
{
private:
    int x;
    int y;
    int speed;
    bool isMove;

public:

    Bullet();

    void plane_fire();

    void enemy_fire();

    void setStatus(bool _isMove);

    bool is_Move()
    {
        return isMove;
    }
    ~Bullet();
};
#endif // BULLET_H
