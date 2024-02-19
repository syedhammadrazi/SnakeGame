#include<SDL.h>
#include "snake.hpp"
#include "fruits.hpp"
#include "score.hpp"
#include<vector>
#include<list>

// This is our class HUMania #05, which handles the main working of the game as defined below
class HUMania
{
    // Creating object of the snake for each level
    // 3 Objects of class snake_lvl_1, snake_lvl_2, and snake_lvl_3
    snake_level_1 snake_lvl_1; // Object 1
    snake_level_2 snake_lvl_2; // Object 2
    snake_level_3 snake_lvl_3; // Object 3

    // 2 Vectors of class apple, and grape
    vector<Apple*>apples; // Many Objects, but same, 4
    vector<Grape*>grapes; // 2 Objects, but same, 5

    // Object of score #07
    Score score_op;

    public:

        // required attributes & functions
        Score score; // current score
        int sequence = 0;
        int counter = 0;
        int count = 0;
        int x,y,a,b;
        int level = 1;
        int level_snake = 1; // default snake level
        bool v = false;
        bool gameStatus(); // checks the state of the game
        void moveSouth(); // moves the snake south
        void moveNorth(); // moves the snake north
        void moveWest(); // moves the snake west
        void moveEast(); // moves the snake east
        void CreateSnake(); // Creates Snake
        void CreateApple(); // Creates Apple
        void DrawApple(); // Draws Apple
        void CreateGrape(); // Creates Grape
        void DrawGrape(); // Draws Grape
        void collision_detection(); // detects collision
        void callScore();
};