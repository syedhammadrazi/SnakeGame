#include "snake.hpp"
#include <iostream>
using namespace std;

// Defining all the functions for snake_level_1
void snake_level_1::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect1, &moverRect1);
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect2, &moverRect2);
}

// defining move east
void snake_level_1::moveE()
{
    if (moverRect.x > 950)
    {
        game_status = false;
        moverRect.x = 950;
    }

    else
    {
        moverRect.x+=10;
        moverRect1.x= (moverRect.x-43);
        moverRect2.x= (moverRect.x-93);
        moverRect1.y=moverRect.y;
        moverRect2.y=moverRect.y;
        srcRect.x = 385;
        srcRect.y = 100;
        srcRect.w = 97;
        srcRect.h = 93;
        srcRect1.x = 392;
        srcRect1.y = 5;
        srcRect1.w = 92;
        srcRect1.h = 82;
        srcRect2.x = 393;
        srcRect2.y = 302;
        srcRect2.h = 91;
        srcRect2.w = 81;
    }
}

// defining move west
void snake_level_1::moveW()
{
    if (moverRect.x < 5)
    {
        game_status = false;
        moverRect.x = 5;
    }

    else
    {
        moverRect.x-=10;
        moverRect1.x= (moverRect.x+45);
        moverRect2.x= (moverRect.x+89);
        moverRect1.y=moverRect.y;
        moverRect2.y=moverRect.y;
        srcRect.x = 290;
        srcRect.y = 198;
        srcRect.w = 97;
        srcRect.h = 93;
        srcRect1.x = 392;
        srcRect1.y = 5;
        srcRect1.w = 92;
        srcRect1.h = 82;
        srcRect2.x = 295;
        srcRect2.y = 400;
        srcRect2.h = 92;
        srcRect2.w = 82;
    }
}

// defining move south
void snake_level_1::moveS()
{
    if (moverRect.y > 550)
    {
        game_status = false;
        moverRect.y = 550;
    }
    else
    {
        moverRect.y+=10;
        moverRect1.y=(moverRect.y-43);
        moverRect2.y=(moverRect.y-93);
        moverRect1.x=moverRect.x;
        moverRect2.x=moverRect.x;
        srcRect.x = 388;
        srcRect.y = 194;
        srcRect.w = 94;
        srcRect.h = 97;
        srcRect1.x = 300;
        srcRect1.y = 5;
        srcRect1.w = 82;
        srcRect1.h = 91;
        srcRect2.x = 394;
        srcRect2.y = 399;
        srcRect2.h = 82;
        srcRect2.w = 91;
    }
}

// defining move north
void snake_level_1::moveN()
{
    if (moverRect.y < 5)
    {
        game_status = false;
        moverRect.y = 5;
    }
    else
    {
        moverRect.y-=10;
        moverRect1.y=(moverRect.y+45);
        moverRect2.y=(moverRect.y+89);
        moverRect1.x=moverRect.x;
        moverRect2.x=moverRect.x;
        srcRect.x = 290;
        srcRect.y = 100;
        srcRect.w = 94;
        srcRect.h = 96;
        srcRect1.x = 300;
        srcRect1.y = 5;
        srcRect1.w = 82;
        srcRect1.h = 91;
        srcRect2.x = 296;
        srcRect2.y = 300;
        srcRect2.h = 82;
        srcRect2.w = 92;
    }
}

// defining custom constructor
void snake_level_1::snakes_level_1(int x, int y)
{
    //src coordinates from assets.png file, they have been found using spritecow.com
    srcRect = {385, 100, 97, 93};
    srcRect1 = {392, 5, 92, 82};
    srcRect2 = {393, 302, 91, 81};

    //it will display the snake on x, y location, the size of the snake varies
    moverRect = {x, y, 46, 46};
    moverRect1 = {x-43, y, 45, 45};
    moverRect2 = {x-93, y, 50, 50};
}