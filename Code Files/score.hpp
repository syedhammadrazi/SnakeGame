#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "drawing.hpp"
#include <iostream>
using namespace std;

// score class #11
class Score
{
    public:
        int score_opt = 0;
        Score()
        {} // default constructor
        Score operator + (int num); // operator overloading
        friend ostream & operator << (ostream &out, const Score &s) // operator overloading
        {
            out << s.score_opt;
            return out; 
        }
    
        void showScore();
        ~Score()
        {}
};