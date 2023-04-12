#include "Boardgame.h"
#include "Object.h"
#include "Plane.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Explosion.h"
#include "TextObject.h"

using namespace BG;

void initMenu(SDL_Renderer* renderer, bool & quit);

int main(int argc, char* argv[])
{
    srand(time(0));
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer;
    SDL_Event event;
    bool quit = false;

    initSDL(window, renderer);

    /// MENU
    initMenu(renderer,quit);

    /// BACKGROUND
    int backgr_main_y = 0;
    int backgr_main_y_ = SCREEN_HEIGHT;
    int backgr_1_y = 0;
    int backgr_2_y = SCREEN_HEIGHT;
    int backgr_3_y = SCREEN_HEIGHT*2;
    int backgr_4_y = SCREEN_HEIGHT*3;

    SDL_Texture* Background = loadTexture(renderer, "C:\\Users\\ASUS\\OneDrive\\Documents\\GitHub\\LTNC_main\\FireMonster\\Fire_Monster\\image\\background.png");
    SDL_Texture* Background_1 = loadTexture(renderer,"C:\\Users\\ASUS\\OneDrive\\Documents\\GitHub\\LTNC_main\\FireMonster\\Fire_Monster\\image\\bg1.png");
    SDL_Texture* Background_2 = loadTexture(renderer,"C:\\Users\\ASUS\\OneDrive\\Documents\\GitHub\\LTNC_main\\FireMonster\\Fire_Monster\\image\\bg2.png");
    SDL_Texture* Background_3 = loadTexture(renderer,"C:\\Users\\ASUS\\OneDrive\\Documents\\GitHub\\LTNC_main\\FireMonster\\Fire_Monster\\image\\bg3.png");
    SDL_Texture* Background_4 = loadTexture(renderer,"C:\\Users\\ASUS\\OneDrive\\Documents\\GitHub\\LTNC_main\\FireMonster\\Fire_Monster\\image\\bg4.png");
    SDL_Texture* Line = loadTexture(renderer,"C:\\Users\\ASUS\\OneDrive\\Documents\\GitHub\\LTNC_main\\FireMonster\\Fire_Monster\\image\\line.png");
    SDL_Rect rect_line = {0,700,640,40};

    /// Plane
    Plane plane(renderer);
    Explosion exp_plane(renderer,"C:\\Users\\ASUS\\OneDrive\\Documents\\GitHub\\LTNC_main\\FireMonster\\Fire_Monster\\image\\BlurPlane.png");
    exp_plane.set_clip();
    int ex;

    /// Mark
    TextObject mark;
    mark.initText(fontText);
    mark.SetColor(TextObject::RED_TEXT);
    int score = 0;

    /// HP
    TextObject Hp;
    Hp.setPos(5,5);
    Hp.SetColor(TextObject::RED_TEXT);

    /// Enemy
    int x = rand() % ( 160 - 0 + 1);

    vector<Enemy> list_enemy;
	for(int i = 1; i <= NUMBER_OF_ENEMY; i++)
    {
        int type = rand() % (TYPE_ENEMY - 1 + 1) + 1;
		Enemy enemy(renderer, type);

		 x += rand() % (200 - 50 + 1);

		 if( x > SCREEN_WIDTH )
         {
             x = rand() % ( 160 - 0 + 1);
         }

		int y = -(rand() % ( SCREEN_HEIGHT/4 - 0 + 1));

		enemy.setPos(x, y);
		list_enemy.push_back(enemy);
	}


	/// Hearticon
	Bullet heart;
	heart.setImg(renderer,"C:\\Users\\ASUS\\OneDrive\\Documents\\GitHub\\LTNC_main\\FireMonster\\Fire_Monster\\image\\heart_icon.png");
	heart.setSize(32,32);
	heart.setStatus(false);
	int heart_x = 200;
	int heart_y = 0;
	heart.setPos(heart_x,heart_y);

    /// Game loop!
    while(!quit)
    {
        while(SDL_PollEvent(&event) != 0)
        {
            if( event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE )
            {
                quit = true;
            }
            plane.move(event);
        }

        SDL_RenderClear(renderer);

        SDL_ShowCursor(false);

        SDL_RenderCopy(renderer,Line,NULL,&rect_line);

        backgr_main_y_ = backgr_main_y + SCREEN_HEIGHT;
        SDL_Rect up_backgrmain2 = {0, backgr_main_y_, SCREEN_WIDTH, SCREEN_HEIGHT};

        SDL_RenderCopy(renderer, Background, NULL, &up_backgrmain2);

        backgr_main_y -= 1;
        SDL_Rect up_backgrmain1 = {0, backgr_main_y, SCREEN_WIDTH, SCREEN_HEIGHT};
        if( backgr_main_y <= -SCREEN_HEIGHT )
        {
            backgr_main_y = 0;
        }

        SDL_RenderCopy(renderer, Background, NULL, &up_backgrmain1);

        backgr_4_y = backgr_3_y + SCREEN_HEIGHT;
        SDL_Rect up_backgr4 = {0,backgr_4_y,SCREEN_WIDTH,SCREEN_HEIGHT};
        SDL_RenderCopy(renderer,Background_4,nullptr, &up_backgr4);

        backgr_3_y = backgr_2_y + SCREEN_HEIGHT;
        SDL_Rect up_backgr3 = {0,backgr_3_y,SCREEN_WIDTH,SCREEN_HEIGHT};
        SDL_RenderCopy(renderer,Background_3,nullptr, &up_backgr3);

        backgr_2_y = backgr_1_y + SCREEN_HEIGHT;
        SDL_Rect up_backgr2 = {0,backgr_2_y,SCREEN_WIDTH,SCREEN_HEIGHT};
        SDL_RenderCopy(renderer,Background_2,nullptr, &up_backgr2);

        backgr_1_y -= 1;
        SDL_Rect up_backgr1 = {0,backgr_1_y,SCREEN_WIDTH,SCREEN_HEIGHT};
        SDL_RenderCopy(renderer,Background_1,nullptr, &up_backgr1);

        if( backgr_3_y <= -(SCREEN_HEIGHT) )
        {
            backgr_1_y = 0;
        }

        plane.update(renderer);

        for (int i = 0; i <= NUMBER_OF_ENEMY - 1; i++)
        {
			if(!list_enemy.at(i).isKilled())
			{
			    for (long long unsigned int j = 0; j < plane.getListBullets().size(); j++)
                {
                    if( checkCollision( list_enemy.at(i).getRect(), plane.getListBullets()[j].getRect()) )
                    {
                        list_enemy.at(i).kill();
                        score += 10;
                        plane.getListBullets()[j].setStatus(false);
                        break;
                    }
			    }

				if( checkCollision( list_enemy.at(i).getRectBullet(), plane.getRect() ) )
                {
                    --plane.hp;
                    list_enemy.at(i).clear_bullet();

                    plane.isShot = true;
                    ex = 0;
                    int x_pos = plane.getRect().x;
                    int y_pos = plane.getRect().y;
                    exp_plane.setPos(x_pos, y_pos);

                    if( plane.hp == 0 )
                    {
                        quit = true;
                    }
                }
                for (long long unsigned int j = 0; j < plane.getListBullets().size(); j++)
                {
                    if( checkCollision(list_enemy.at(i).getRectBullet(), plane.getListBullets()[j].getRect()) )
                    {
                        list_enemy.at(i).clear_bullet();
                    }
			    }
			    if( list_enemy.at(i).getRect().y == 700 )
                {
                    score -= 5;
                }
			}
            list_enemy.at(i).update(renderer);
		}

        heart.setStatus(true);
        if( heart.is_Move())
        {
            heart.icon_move();

            heart.show(renderer);
        }

		if ( ex < NUM_OF_FRAME )
        {
            exp_plane.set_frame(ex);
            exp_plane.showEx(renderer);
            ex++;
        }
        else
        {
            plane.isShot = false;
        }

        if( checkCollision(heart.getRect(),plane.getRect()) )
        {
            plane.hp++;
            heart_x = rand() % (SCREEN_WIDTH - 20 -10) + 1;
            heart_y = -(SCREEN_HEIGHT*4);
            heart.setPos(heart_x,heart_y);
        }

        Hp.SetText("HP: " + to_string(plane.hp) );
        Hp.CreateGameText(fontText,renderer,100,50);

        mark.SetText( "SCORE: " + to_string(score) );
        mark.CreateGameText(fontText,renderer,100,50);
        SDL_RenderCopy(renderer,Line,NULL,&rect_line);
        SDL_RenderPresent(renderer);
    }

    quitSDL(window, renderer);

    return 0;
}

void initMenu(SDL_Renderer* renderer,bool& quit)
{
    TTF_Font* fontMenu = NULL;
    SDL_Texture* Menu = NULL;
    SDL_Texture* Help = NULL;
    bool IsRunningMenu = false;
    bool help = false;
    fontMenu = TTF_OpenFont("C:\\Users\\ASUS\\OneDrive\\Documents\\GitHub\\LTNC_main\\FireMonster\\Fire_Monster\\font\\VCR_OSD_MONO_1.001.ttf",100);
    Menu = loadTexture(renderer,"C:\\Users\\ASUS\\OneDrive\\Documents\\GitHub\\LTNC_main\\FireMonster\\Fire_Monster\\image\\FIRE_MONSTER.png");
    Help = loadTexture(renderer,"C:\\Users\\ASUS\\OneDrive\\Documents\\GitHub\\LTNC_main\\FireMonster\\Fire_Monster\\image\\help.png");

    SDL_Rect pos_arr[kMenuItemNum];
    pos_arr[0].x = 200;
    pos_arr[0].y = 300;

    pos_arr[1].x = 200;
    pos_arr[1].y = 400;

    pos_arr[2].x = 200;
    pos_arr[2].y = 500;

    TextObject text_menu[kMenuItemNum];

    text_menu[0].SetText("PLAY");
    text_menu[0].setPos(pos_arr[0].x, pos_arr[0].y);

    text_menu[1].SetText("EXIT");
    text_menu[1].setPos(pos_arr[1].x, pos_arr[1].y);

    text_menu[2].SetText("HELP");
    text_menu[2].setPos(pos_arr[2].x, pos_arr[2].y);

    bool selected[kMenuItemNum] = {0,0};
    int xm = 0;
    int ym = 0;

    SDL_Event menu_event;

    while(!quit)
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,Menu,NULL,NULL);
        for(int i = 0 ; i < kMenuItemNum; ++i)
        {
            text_menu[i].CreateGameText(fontMenu,renderer,90,50);
        }

        while(SDL_PollEvent(&menu_event))
        {
            switch (menu_event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_MOUSEMOTION:
                {
                    xm = menu_event.motion.x;
                    ym = menu_event.motion.y;

                    for(int i = 0; i < kMenuItemNum; ++i)
                    {
                        if(CheckFocusWithRect(xm, ym, text_menu[i].getRect()))
                        {
                            if(selected[i] == false)
                            {
                                selected[i] = 1;
                                text_menu[i].SetColor(TextObject::RED_TEXT);
                            }
                        }
                        else
                        {
                            if(selected[i] == true)
                            {
                                selected[i] = 0;
                                text_menu[i].SetColor(TextObject::WHITE_TEXT);
                            }
                        }
                    }
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                {
                    xm = menu_event.button.x;
                    ym = menu_event.button.y;

                    for(int i = 0; i < kMenuItemNum; ++i)
                    {
                        if(CheckFocusWithRect(xm, ym, text_menu[i].getRect()))
                        {
                            if(i == 0)
                            {
                                IsRunningMenu = true;
                            }
                            else if(i == 2)
                            {
                                help = true;
                            }
                            quit = true;
                            break;
                        }
                    }
                }
                break;
            case SDL_KEYDOWN:
                if(menu_event.key.keysym.sym == SDLK_ESCAPE)
                {
                    quit = true;
                }
            default:
                break;
            }
        }
        SDL_RenderPresent(renderer);
    }
    if(help == true)
        {
            bool quit2 = false;

            SDL_Event help_event;

            while(!quit2)
            {
                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer,Help,NULL,NULL);

                while(SDL_PollEvent(&help_event)!= 0)
                {
                    if(help_event.type == SDL_QUIT)
                    {
                        quit2 = true;
                    }
                    else if(help_event.type == SDL_MOUSEBUTTONDOWN)
                        {
                            IsRunningMenu = true;
                            quit2 = true;
                            break;
                        }
                }
                 SDL_RenderPresent(renderer);
            }
        }

    if (IsRunningMenu)
    {
        quit = false;
    }

}
