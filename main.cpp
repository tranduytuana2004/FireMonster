#include "Boardgame.h"
#include "Object.h"
#include "Plane.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Explosion.h"

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

    SDL_Texture* Background = loadTexture(renderer, "C:\\Users\\ASUS\\OneDrive\\Documents\\GitHub\\LTNC_main\\FireMonster\\Fire_Monster\\image\\background.png");

    Plane plane(renderer);

    Explosion exp_plane(renderer,"C:\\Users\\ASUS\\OneDrive\\Documents\\GitHub\\LTNC_main\\FireMonster\\Fire_Monster\\image\\BlurPlane.png");

    exp_plane.set_clip();
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
                    -- plane.hp;
                    for(int ex = 0; ex < 8; ex++)
                    {
                        int x_pos = plane.getRect().x +  plane.getRect().w; - EXPLOSION_WIDTH;
                        int y_pos = plane.getRect().y +  plane.getRect().h; - EXPLOSION_HEIGHT;

                        exp_plane.set_frame(ex);
                        exp_plane.setPos(x_pos,y_pos);
                        exp_plane.showEx(renderer);
                        SDL_Delay(100);
                        SDL_RenderPresent(renderer);
                    }
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
