#include "fruits.hpp"

// defining default constructor for class fruit
fruits::fruits()
{

}

// defining draw function for apple
void Apple::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect); // drawing
}

// defining default constructor for apple
Apple::Apple()
{

}

// defining custom constructor for apple
Apple::Apple(int x, int y)
{
    srcRect = {20, 269, 90, 93}; // x, y, width, height
    moverRect = {x, y, 50, 50}; // where to draw
}

// defining draw function for grape
void Grape::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect); // drawing
}

// defining default constructor for grape
Grape::Grape()
{

}

// defining custom constructor for grape
Grape::Grape(int x, int y)
{
    srcRect = {32, 163, 66, 97}; // x, y , width, height
    moverRect = {x, y, 50, 50}; // where to draw
}
