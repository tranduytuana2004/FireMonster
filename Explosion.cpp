#include "Explosion.h"

Explosion::Explosion( SDL_Renderer* renderer, string path )
{
    setImg(renderer, path);
}

void Explosion::set_clip()
{
    clip[0].x = 0;
    clip[0].y = 0;
    clip[0].w = EXPLOSION_WIDTH;
    clip[0].h = EXPLOSION_HEIGHT;

    clip[1].x = EXPLOSION_WIDTH;
    clip[1].y = 0;
    clip[1].w = EXPLOSION_WIDTH;
    clip[1].h = EXPLOSION_HEIGHT;

    clip[2].x = EXPLOSION_WIDTH * 2;
    clip[2].y = 0;
    clip[2].w = EXPLOSION_WIDTH;
    clip[2].h = EXPLOSION_HEIGHT;

    clip[3].x = EXPLOSION_WIDTH * 3;
    clip[3].y = 0;
    clip[3].w = EXPLOSION_WIDTH;
    clip[3].h = EXPLOSION_HEIGHT;

    clip[4].x = EXPLOSION_WIDTH * 4;
    clip[4].y = 0;
    clip[4].w = EXPLOSION_WIDTH;
    clip[4].h = EXPLOSION_HEIGHT;

    clip[5].x = EXPLOSION_WIDTH * 5;
    clip[5].y = 0;
    clip[5].w = EXPLOSION_WIDTH;
    clip[5].h = EXPLOSION_HEIGHT;

    clip[6].x = EXPLOSION_WIDTH * 6;
    clip[6].y = 0;
    clip[6].w = EXPLOSION_WIDTH;
    clip[6].h = EXPLOSION_HEIGHT;

    clip[7].x = EXPLOSION_WIDTH * 7;
    clip[7].y = 0;
    clip[7].w = EXPLOSION_WIDTH;
    clip[7].h = EXPLOSION_HEIGHT;
}

void Explosion::set_frame( const int& _frame )
{
    frame = _frame;
}

void Explosion::showEx( SDL_Renderer* renderer )
{
    if( frame >= NUM_OF_FRAME )
    {
        frame = 0;
    }

    BG::loadRendererClip(this -> body,renderer, &clip[frame], rect.x, rect.y);
}
