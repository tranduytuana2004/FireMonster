#ifndef BOARDGAME_H
#define BOARDGAME_H

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

static const int SCREEN_WIDTH  = 1000;
static const int SCREEN_HEIGHT = 800;
static const int NUMBER_OF_ENEMY = 20;
static const int WIDTH_ENEMY = 85;
static const int HEIGHT_ENEMY = 85;
static const int WIDTH_BULLET_PLANE = 20;
static const int HEIGHT_BULLET_PLANE = 55;
static const int WIDTH_BULLET_ENEMY = 25;
static const int HEIGHT_BULLET_ENEMY = 25;
static const int SPEED_BULLET_PLANE = 20;
static const int SPEED_BULLET_ENEMY = 2;

namespace BG
{
    void logSDLError(const string& msg, bool fatal);

    void initSDL(SDL_Window* window, SDL_Renderer*& renderer);

    void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

    SDL_Texture* loadTexture(SDL_Renderer* renderer, string path);

    bool checkCollision(SDL_Rect a, SDL_Rect b);
}

#endif // BOARDGAME_H
