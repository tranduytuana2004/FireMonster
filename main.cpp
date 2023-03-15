#include "Boardgame.h"
#include "Object.h"
#include "Plane.h"
#include "Bullet.h"
#include "Enemy.h"

using namespace BG;

int main(int argc, char* argv[])
{
    srand(time(0));
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer;
    SDL_Event event;
    bool quit = false;
    int backgr_y = 0;
    int backgr_y_ = SCREEN_HEIGHT;

    initSDL(window, renderer);

    SDL_Texture* Background = loadTexture(renderer, "D:\\Code\\banga\\FireMonster\\image\\background.png");

    Plane plane(renderer,"D:\\Code\\banga\\FireMonster\\image\\Plane.png");

    vector<Enemy> list_enemy;
	for(int i = 1; i < NUMBER_OF_ENEMY; i++) {
        int type = rand() % (3-1+1)+1;
		Enemy enemy(renderer, type);

		int x = rand() % (SCREEN_WIDTH - enemy.getRect().w );
		if( x < enemy.getRect().w )
        {
            x = enemy.getRect().w;
        }

		int y = 0;

		enemy.setPos(x, y);
		list_enemy.push_back(enemy);
	}

    while(!quit)
    {
        while(SDL_PollEvent(&event) != 0)
        {
            if( event.type == SDL_QUIT )
            {
                quit = true;
            }
            plane.move(event);
        }

        SDL_RenderClear(renderer);

        backgr_y_ = backgr_y + SCREEN_HEIGHT;
        SDL_Rect up_backgr2 = {0, backgr_y_, SCREEN_WIDTH, SCREEN_HEIGHT};

        SDL_RenderCopy(renderer, Background, NULL, &up_backgr2);
        //SDL_RenderPresent(renderer);

        backgr_y -= 1;
        SDL_Rect up_backgr1 = {0, backgr_y, SCREEN_WIDTH, SCREEN_HEIGHT};
        if( backgr_y <= -SCREEN_HEIGHT )
        {
            backgr_y = 0;
        }

        SDL_RenderCopy(renderer, Background, NULL, &up_backgr1);

        plane.update(renderer);

        for (int i = 0; i < NUMBER_OF_ENEMY - 1; i++)
        {
			if(!list_enemy.at(i).isKilled())
			{
				if( checkCollision( list_enemy.at(i).getRect(), plane.getRectBullet() ) )
                {
					list_enemy.at(i).kill();
						//score += 100;
						plane.clear_bullet();
						break;
				}
				if( checkCollision( list_enemy.at(i).getRectBullet(), plane.getRect() ) )
                {
                   // plane.kill();
                   // plane.Free();
                    -- plane.hp;
                    if( plane.hp == 0 )
                    {
                        plane.setPos(0,0);
                        plane.setSize(0,0);
                        quit = true;
                    }
                    list_enemy.at(i).clear_bullet();
                    break;
                }
				list_enemy.at(i).update(renderer);
			}
		}
        SDL_RenderPresent(renderer);
    }

    quitSDL(window, renderer);
    return 0;
}
