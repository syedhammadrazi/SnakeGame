#include<SDL.h>
#include<SDL_image.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<SDL_mixer.h>
#include<stdlib.h>
#include<SDL_ttf.h>
#include<time.h>
#include "drawing.hpp"
#pragma once

// This is our game class #10
class Game
{
    //screen dimension constants
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 600;

    //the window we will be rendering to
    SDL_Window* gWindow = NULL;

    //current displayed texture
    SDL_Texture* gTexture = NULL;

    Game();
    // ~Game();
    static Game* instance;

    public:
        static Game* Instance();
        int state = 0;
        bool init();
        bool load_mainMenu();       // loading background texture for the main menu
        bool loadMedia();           // loading background texture for the game
        bool load_end();
        bool load_instructions();
        void close();
        SDL_Texture* loadTexture(std::string path);
        void display();
        void run();
};