#include<SDL.h>
#include "drawing.hpp"

// This our class #02, which is the parent class for class apple and grape
class fruits
{
    public:
        SDL_Rect srcRect, moverRect; // has its own srcRect and moverRect to draw fruit
        virtual void draw() = 0; // pure virtual function of draw
        fruits(); // default constructor
};

// This is the child class of fruit, apple class #03
class Apple : public fruits
{
    public:
        Apple(); // default constructor
        Apple(int x, int y); // constructor called to get coordinates for where to draw
        void draw(); // draw function
};

// This is the child class of fruit, grape class #04
class Grape : public fruits
{
    public:
        Grape(); // default constructor
        Grape(int x, int y); // constructor called to get coordinates for where to draw
        void draw(); // draw function
};