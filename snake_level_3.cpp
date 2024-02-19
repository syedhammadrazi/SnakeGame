#include "snake.hpp"
#include <iostream>
// Defining all the functions for snake_level_3
void snake_level_3::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect1, &moverRect1);
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect3, &moverRect3);
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect4, &moverRect4);
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect2, &moverRect2);
}

void snake_level_3::moveE()
{
    if (moverRect.x > 950)
    {
        game_status = false;
        moverRect.x = 950;
    }

    else
    {
        moverRect.x+=20;
        moverRect1.x=(moverRect.x-44);
        moverRect3.x=(moverRect.x-89);
        moverRect4.x=(moverRect.x-134);
        moverRect2.x=(moverRect.x-184);
        moverRect1.y=moverRect.y;
        moverRect2.y=moverRect.y;
        moverRect3.y=moverRect.y;
        moverRect4.y=moverRect.y;
        srcRect.x = 385;
        srcRect.y = 100;
        srcRect.w = 97;
        srcRect.h = 93;
        srcRect1.x = 392;
        srcRect1.y = 5;
        srcRect1.w = 92;
        srcRect1.h = 82;
        srcRect3.x = 392;
        srcRect3.y = 5;
        srcRect3.w = 92;
        srcRect3.h = 82;
        srcRect4.x = 392;
        srcRect4.y = 5;
        srcRect4.w = 92;
        srcRect4.h = 82;
        srcRect2.x = 393;
        srcRect2.y = 302;
        srcRect2.h = 91;
        srcRect2.w = 81;
    }
}

void snake_level_3::moveW()
{
    if (moverRect.x < 5)
    {
        game_status = false;
        moverRect.x = 5;
    }

    else
    {
        moverRect.x-=20;
        moverRect1.x=(moverRect.x+45);
        moverRect3.x=(moverRect.x+89);
        moverRect4.x=(moverRect.x+133);
        moverRect2.x=(moverRect.x+177);
        moverRect1.y=moverRect.y;
        moverRect2.y=moverRect.y;
        moverRect3.y=moverRect.y;
        moverRect4.y=moverRect.y;
        srcRect.x = 290;
        srcRect.y = 198;
        srcRect.w = 97;
        srcRect.h = 93;
        srcRect1.x = 392;
        srcRect1.y = 5;
        srcRect1.w = 92;
        srcRect1.h = 82;
        srcRect3.x = 392;
        srcRect3.y = 5;
        srcRect3.w = 92;
        srcRect3.h = 82;
        srcRect4.x = 392;
        srcRect4.y = 5;
        srcRect4.w = 92;
        srcRect4.h = 82;
        srcRect2.x = 295;
        srcRect2.y = 400;
        srcRect2.h = 92;
        srcRect2.w = 82;
    }
}

void snake_level_3::moveS()
{
    if (moverRect.y > 550)
    {
        game_status = false;
        moverRect.y = 550;
    }
    else
    {
        moverRect.y+=20;
        moverRect1.y=(moverRect.y-44);
        moverRect3.y=(moverRect.y-89);
        moverRect4.y=(moverRect.y-134);
        moverRect2.y=(moverRect.y-184);
        moverRect1.x=moverRect.x;
        moverRect2.x=moverRect.x;
        moverRect3.x=moverRect.x;
        moverRect4.x=moverRect.x;
        srcRect.x = 388;
        srcRect.y = 194;
        srcRect.w = 94;
        srcRect.h = 97;
        srcRect1.x = 300;
        srcRect1.y = 5;
        srcRect1.w = 82;
        srcRect1.h = 91;
        srcRect3.x = 300;
        srcRect3.y = 5;
        srcRect3.w = 82;
        srcRect3.h = 91;
        srcRect4.x = 300;
        srcRect4.y = 5;
        srcRect4.w = 82;
        srcRect4.h = 91;
        srcRect2.x = 394;
        srcRect2.y = 399;
        srcRect2.h = 82;
        srcRect2.w = 91;
    }
}

void snake_level_3::moveN()
{
    if (moverRect.y < 5)
    {
        game_status = false;
        moverRect.y = 5;
    }
    else
    {
        moverRect.y-=20;
        moverRect1.y=(moverRect.y+45);
        moverRect3.y=(moverRect.y+89);
        moverRect4.y=(moverRect.y+133);
        moverRect2.y=(moverRect.y+177);
        moverRect1.x=moverRect.x;
        moverRect2.x=moverRect.x;
        moverRect3.x=moverRect.x;
        moverRect4.x=moverRect.x;
        srcRect.x = 290;
        srcRect.y = 100;
        srcRect.w = 94;
        srcRect.h = 96;
        srcRect1.x = 300;
        srcRect1.y = 5;
        srcRect1.w = 82;
        srcRect1.h = 91;
        srcRect3.x = 300;
        srcRect3.y = 5;
        srcRect3.w = 82;
        srcRect3.h = 91;
        srcRect4.x = 300;
        srcRect4.y = 5;
        srcRect4.w = 82;
        srcRect4.h = 91;
        srcRect2.x = 296;
        srcRect2.y = 300;
        srcRect2.h = 82;
        srcRect2.w = 92;
    }
}

void snake_level_3::snakes_level_3(int x, int y)
{
    //src coordinates from assets.png file, they have been found using spritecow.com
    srcRect = {385, 100, 97, 93};
    srcRect1 = {392, 5, 92, 82};
    srcRect3 = {392, 5, 92, 82};
    srcRect4 = {392, 5, 92, 82};
    srcRect2 = {393, 302, 91, 81};

    //it will display the snake on x, y location, the size of the snake varies
    moverRect = {x, y, 46, 46};
    moverRect1 = {x-43, y, 45, 45};
    moverRect3 = {x-93, y, 45, 45};
    moverRect4 = {x-143, y, 45, 45};
    moverRect2 = {x-193, y, 50, 50};
}