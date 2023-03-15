#include "Plane.h"
#include "Object.h"
#include "Bullet.h"

Plane::Plane()
{
    x = 0;
    y = 0;
}

Plane::Plane(SDL_Renderer* renderer, string path)
{
    x = SCREEN_WIDTH / 2;
    y = SCREEN_HEIGHT *3 / 4;

    setPos(x,y);

    setImg(renderer, path);

    list_bullets.setImg(renderer, "D:\\Code\\banga\\FireMonster\\image\\Bullet.png");

    list_bullets.setPos(x,y);
    list_bullets.setSize(WIDTH_BULLET_PLANE,HEIGHT_BULLET_PLANE);
}

void Plane::move(SDL_Event event)
{
    if( event.type == SDL_MOUSEMOTION )
    {
        rect.x = event.motion.x - rect.w / 2;
        rect.y = event.motion.y - rect.h / 2;
    }
    if( event.type == SDL_MOUSEBUTTONDOWN )
    {
        if( !list_bullets.is_Move() )
        {
            list_bullets.setPos(rect.x + rect.w/2 - list_bullets.getRect().w/2, rect.y +15);
            list_bullets.setStatus(true);
        }
    }
}

void Plane::update(SDL_Renderer* renderer)
{
    show(renderer);

    if( list_bullets.is_Move())
    {
        list_bullets.plane_fire();
        list_bullets.show(renderer);
    }
}

void Plane::clear_bullet()
{
    list_bullets.setPos(0,0);
    list_bullets.setStatus(false);
}

SDL_Rect Plane::getRectBullet()
{
    return list_bullets.getRect();
}

void Plane::kill()
{

}

Plane::~Plane()
{

}
