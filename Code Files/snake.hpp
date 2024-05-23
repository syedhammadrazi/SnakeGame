#include<SDL.h>
#include "drawing.hpp"

// Defining a class snake #06 which contains the functions (pure virtual functions) that will be utilised
// by child classes (snake_level_1, snake_level_2, snake_level_3)
// Each child class represents the level of the snake
class snake
{
    public:
    bool game_status = true; // default game status
    virtual void draw() = 0; // pure virtual function
    virtual void moveE() = 0; // pure virtual function
    virtual void moveS() = 0; // pure virtual function
    virtual void moveN() = 0; // pure virtual function
    virtual void moveW() = 0; // pure virtual function
    snake() // default constructor
    {}
    ~snake()
    {}
};

// Child class 1 #07
class snake_level_1 : public snake
{
    public:
        SDL_Rect srcRect, moverRect;
        SDL_Rect srcRect1, moverRect1;
        SDL_Rect srcRect2, moverRect2;

        snake_level_1() // default constructor
        {}
        void snakes_level_1(int x, int y); // custom constructor
        void draw(); // draw function
        void moveE(); // move East
        void moveS(); // move South
        void moveN(); // move North
        void moveW(); // move West
        ~snake_level_1()
        {}
};

// Child class 2 #08
class snake_level_2 : public snake
{
    public:
        SDL_Rect srcRect, moverRect;
        SDL_Rect srcRect1, moverRect1;
        SDL_Rect srcRect2, moverRect2;
        SDL_Rect srcRect3, moverRect3;

        snake_level_2() // default constructor
        {}
        void snakes_level_2(int x, int y); // custom constructor
        void draw(); // draw function
        void moveE(); // move East
        void moveS(); // move South
        void moveN(); // move North
        void moveW(); // move West
        ~snake_level_2()
        {}
};

// Child class 3 #09
class snake_level_3 : public snake
{
    public:
        SDL_Rect srcRect, moverRect;
        SDL_Rect srcRect1, moverRect1;
        SDL_Rect srcRect2, moverRect2;
        SDL_Rect srcRect3, moverRect3;
        SDL_Rect srcRect4, moverRect4;

        snake_level_3() // default constructor
        {}
        void snakes_level_3(int x, int y); // custom constructor
        void draw(); // draw function
        void moveE(); // move East
        void moveS(); // move South
        void moveN(); // move North
        void moveW(); // move West
        ~snake_level_3()
        {}
};