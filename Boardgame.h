#ifndef BOARDGAME_H
#define BOARDGAME_H

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

static const int SCREEN_WIDTH  = 1000;
static const int SCREEN_HEIGHT = 800;

namespace BG
{
    void logSDLError(const string& msg, bool fatal);
    void initSDL(SDL_Window* window, SDL_Renderer*& renderer);
    void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
    SDL_Texture* loadTexture(SDL_Renderer* renderer, string path);
    bool checkCollision(SDL_Rect a, SDL_Rect b);
}

#endif // BOARDGAME_H
