#include "Plane.h"
#include "Object.h"
#include "Bullet.h"

Plane::Plane()
{
    x = 0;
    y = 0;
}

Plane::Plane(SDL_Renderer* renderer)
{
    x = SCREEN_WIDTH / 2;
    y = SCREEN_HEIGHT *3 / 4;

    isShot = false;

    setPos(x,y);

    setImg(renderer, "C:\\Users\\ASUS\\OneDrive\\Documents\\GitHub\\LTNC_main\\FireMonster\\Fire_Monster\\image\\Plane.png");

    bullet.setImg(renderer, "C:\\Users\\ASUS\\OneDrive\\Documents\\GitHub\\LTNC_main\\FireMonster\\Fire_Monster\\image\\Bullet.png");

    bullet.setPos(x,y);

    bullet.setSize(WIDTH_BULLET_PLANE,HEIGHT_BULLET_PLANE);
}

void Plane::move(SDL_Event event)
{
    if( event.type == SDL_MOUSEMOTION )
    {
        rect.x = event.motion.x - rect.w / 2;
        rect.y = event.motion.y - rect.h / 2;
        if (rect.y < 2*SCREEN_HEIGHT/3)
        {
            rect.y = 2*SCREEN_HEIGHT/3-1;
        }
    }
    if( event.type == SDL_MOUSEBUTTONDOWN )
    {
            bullet.setPos(rect.x + rect.w/2 - bullet.getRect().w/2, rect.y +15);
            bullet.setStatus(true);
            list_bullets.push_back(bullet);
    }
}

void Plane::update(SDL_Renderer* renderer)
{
    if( !isShot )
    {
        show(renderer);
    }
    for(int i = 0; i < list_bullets.size(); i++)
    {
        if( list_bullets[i].is_Move())
        {
            list_bullets[i].plane_fire();
            list_bullets[i].show(renderer);
        }
        else
        {
            list_bullets.erase(list_bullets.begin(), list_bullets.begin() + i);
        }
    }
}

SDL_Rect Plane::getRectBullet()
{
    return bullet.getRect();
}

Plane::~Plane()
{

}
