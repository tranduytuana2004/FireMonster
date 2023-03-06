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

    initSDL(window, renderer);

    SDL_Texture* Background = loadTexture(renderer, "D:\\Code\\banga\\FireMonster\\image\\background.png");

    Plane plane(renderer,"D:\\Code\\banga\\FireMonster\\image\\SpaceThreat1.png");

    vector<Enemy> list_enemy;
	for (int i = 1; i < 4; i++) {
		Enemy enemy(renderer, i);

		int x = rand() % (SCREEN_WIDTH - enemy.getRect().w);
		if (x < enemy.getRect().w) x = enemy.getRect().w;

		int y = rand() % SCREEN_HEIGHT/4;

		enemy.setPos(x, y);
		list_enemy.push_back(enemy);
	}


    while(!quit)
    {
        while(SDL_PollEvent(&event) != 0)
        {
            if(event.type == SDL_QUIT)
            {
                quit = true;
            }
            plane.move(event);
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, Background, NULL, NULL);
        plane.update(renderer);
        for (int i = 0; i < 3; i++) {
			if (!list_enemy.at(i).isKilled()) {
				if (checkCollision(list_enemy.at(i).getRect(), plane.getRectBullet())) {
					list_enemy.at(i).kill();
						//score += 100;
						break;
						//plane.getBullet().setStatus(false);
				}
				list_enemy.at(i).update(renderer);
			}
		}
        SDL_RenderPresent(renderer);
    }

    quitSDL(window, renderer);
    return 0;
}
