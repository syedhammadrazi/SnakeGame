#include<SDL.h>
#pragma once

// This our class #01, which is responsible for rendering the assets, background etc
class Drawing
{
    public:
        //the window renderer
        static SDL_Renderer* gRenderer;

        //global reference to png image sheets
        static SDL_Texture* assets;
};