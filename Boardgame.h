#ifndef BOARDGAME_H
#define BOARDGAME_H

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

using namespace std;
static  TTF_Font* fontText = NULL;
static const int SCREEN_WIDTH  = 640;
static const int SCREEN_HEIGHT = 800;
static const int NUMBER_OF_ENEMY = 5;
static const int WIDTH_ENEMY = 85;
static const int HEIGHT_ENEMY = 85;
static const int WIDTH_BULLET_PLANE = 20;
static const int HEIGHT_BULLET_PLANE = 55;
static const int WIDTH_BULLET_ENEMY = 25;
static const int HEIGHT_BULLET_ENEMY = 25;
static const int SPEED_BULLET_PLANE = 10;
static int SPEED_BULLET_ENEMY = 2;
static const int HP_DEFAULT = 5;
static const double EXPLOSION_WIDTH = 85;
static const double EXPLOSION_HEIGHT = 51;
static const int NUM_OF_FRAME = 8;
static const int TYPE_ENEMY = 3;
static const int kMenuItemNum = 3;
static const int line_y = 700;
static Mix_Chunk* sound_bullet;

namespace BG
{
    void logSDLError(const string& msg, bool fatal);

    void initSDL(SDL_Window* window, SDL_Renderer*& renderer);

    void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

    SDL_Texture* loadTexture(SDL_Renderer* renderer, string path);

    bool checkCollision(SDL_Rect a, SDL_Rect b);

    void loadRendererClip(SDL_Texture* body, SDL_Renderer* renderer, SDL_Rect* clip, int x, int y);

    bool CheckFocusWithRect( int& x, int& y, SDL_Rect rect);
}

#endif // BOARDGAME_H
