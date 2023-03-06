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
    bullet.setImg(renderer, "D:\\Code\\banga\\FireMonster\\image\\BulletThreat.png");
    bullet.setPos(x,y);
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
        if( !bullet.is_Move() )
        {
            bullet.setPos(rect.x + rect.w/2 - bullet.getRect().w/2, rect.y + bullet.getRect().h);
            bullet.setStatus(true);
        }
    }
}

void Plane::update(SDL_Renderer* renderer)
{
    show(renderer);

    if( bullet.is_Move())
    {
        bullet.fire();
        bullet.show(renderer);
    }
}

SDL_Rect Plane::getRectBullet()
{
    return bullet.getRect();
}

Plane::~Plane()
{

}
