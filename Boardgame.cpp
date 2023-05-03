#include "Boardgame.h"

using namespace std;

void BG::logSDLError(const string& msg, bool fatal)
{
    cout << msg << "Error: " << SDL_GetError() << endl;
    if( fatal )
    {
        SDL_Quit();
        exit(1);
    }
}

void BG::initSDL(SDL_Window* window, SDL_Renderer*& renderer)
{
    if( SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        logSDLError("SDL_Init",true);
    }

    window = SDL_CreateWindow("FireChicken", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if( window == nullptr )
    {
        logSDLError("CreatWindow", true);
    }

    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);
    if( renderer == nullptr )
    {
        logSDLError("CreateRenderer",true);
    }

    if( TTF_Init() == -10 )
    {
        logSDLError("TTF",true);
    }

    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) < 0 )
    {
        logSDLError("MIXER",true);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void BG::quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Texture* BG::loadTexture(SDL_Renderer* renderer, string path)
{
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if( newTexture == nullptr )
        {
            cout << "Can't create texture from surface: " << SDL_GetError() << endl;
        }
    else
        {
            SDL_FreeSurface( loadedSurface );
        }

    return newTexture;
}

bool BG::checkCollision(SDL_Rect a, SDL_Rect b)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

        if ( bottomA <= topB )
        {
            return false;
        }

    if ( topA >= bottomB )
    {
        return false;
    }

    if ( rightA <= leftB )
    {
        return false;
    }

    if ( leftA >= rightB )
    {
        return false;
    }

    /// If none of the sides from A are outside B
    return true;
}

void BG::loadRendererClip(SDL_Texture* body, SDL_Renderer* renderer, SDL_Rect* clip, int x, int y)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_RenderCopy(renderer,body,clip,&offset);
}

bool BG::CheckFocusWithRect( int& x, int& y, SDL_Rect rect)
{
    if( x >= rect.x && x <= rect.x + 80 &&
        y >= rect.y && y <= rect.y + 50 )
    {
        return true;
    }
    return false;
}
