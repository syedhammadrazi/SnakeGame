#include<iostream>
#include<cmath>
#include "HUMania.hpp"
using namespace std;

void HUMania::callScore()
{
    score_op.score_opt = counter;
    score_op.showScore();
}

void HUMania::CreateSnake() // Creation of snake
{
    // Default level when the game begins will be
    if(level_snake==1)
    {
        snake_lvl_1.snakes_level_1(500, 300);
    }
    else if(level_snake==2)
    {
        snake_lvl_2.snakes_level_2(500, 300); // level 2 snake
    }
    else
    {
        snake_lvl_3.snakes_level_3(500, 300); // level 3 snake
    }
}

bool HUMania::gameStatus() // defining game status
{
    if (snake_lvl_1.game_status == false) // if level 1 snake collides with the walls, game ends
    {
        snake_lvl_1.game_status = true;
        counter = 0;
        return(false);
    }
    else if (snake_lvl_2.game_status == false) // if level 2 snake collides with the walls, game ends
    { 
        snake_lvl_1.game_status = true;
        snake_lvl_2.game_status = true;
        counter = 0;
        return(false);
    }
    else if (snake_lvl_3.game_status == false) // if level 3 snake collides with the walls, game ends
    { 
        snake_lvl_1.game_status = true;
        snake_lvl_2.game_status = true;
        snake_lvl_3.game_status = true;
        counter = 0;
        return(false);
    }
    else
    {
        return true; // else game keeps on working
    }
}

// Using conditional statements the level of the snake will change
// It makes the snake move south
void HUMania::moveSouth()
{
    if(level_snake==1)
    {
        snake_lvl_1.draw(); // draws its south movement
        snake_lvl_1.moveS();// makes the snake move
        if(v==true)
        {
            v = false;
            count++;
        }
        else
        {   
            if(count<5)
            {
                count++;
            }
            else
            {
                count = 0;
                collision_detection(); // checks for collision dection
            }
        }
    }
    else if(level_snake==2) // for level 2 snake
    {
        snake_lvl_2.draw();
        snake_lvl_2.moveS();
        if(v==true)
        {
            v = false;
            count++;
        }
        else
        {   
            if(count<5)
            {
                count++;
            }
            else
            {
                count = 0;
                collision_detection();
            }
        }
    }
    else // for level 3 snake
    {
        snake_lvl_3.draw();
        snake_lvl_3.moveS();
        if(v==true)
        {
            v = false;
            count++;
        }
        else
        {   
            if(count<5)
            {
                count++;
            }
            else
            {
                count = 0;
                collision_detection();
            }
        }
    }
}

// Does the same thing as moveSouth but for north direction
void HUMania::moveNorth()
{
    if(level_snake==1)
    {
        snake_lvl_1.draw();
        snake_lvl_1.moveN();
        if(v==true)
        {
            v = false;
            count++;
        }
        else
        {   
            if(count<5)
            {
                count++;
            }
            else
            {
                count = 0;
                collision_detection();
            }
        }
    }
    else if(level_snake==2)
    {
        snake_lvl_2.draw();
        snake_lvl_2.moveN();
        if(v==true)
        {
            v = false;
            count++;
        }
        else
        {   
            if(count<5)
            {
                count++;
            }
            else
            {
                count = 0;
                collision_detection();
            }
        }
    }
    else
    {
        snake_lvl_3.draw();
        snake_lvl_3.moveN();
        if(v==true)
        {
            v = false;
            count++;
        }
        else
        {   
            if(count<5)
            {
                count++;
            }
            else
            {
                count = 0;
                collision_detection();
            }
        }
    }
}

// Does the same thing as moveSouth, but for west direction
void HUMania::moveWest()
{
    if(level_snake==1)
    {
        snake_lvl_1.draw();
        snake_lvl_1.moveW();
        if(v==true)
        {
            v = false;
            count++;
        }
        else
        {   
            if(count<5)
            {
                count++;
            }
            else
            {
                count = 0;
                collision_detection();
            }
        }
    }
    else if(level_snake==2)
    {
        snake_lvl_2.draw();
        snake_lvl_2.moveW();
        if(v==true)
        {
            v = false;
            count++;
        }
        else
        {   
            if(count<5)
            {
                count++;
            }
            else
            {
                count = 0;
                collision_detection();
            }
        }
    }
    else
    {
        snake_lvl_3.draw();
        snake_lvl_3.moveW();
        if(v==true)
        {
            v = false;
            count++;
        }
        else
        {   
            if(count<5)
            {
                count++;
            }
            else
            {
                count = 0;
                collision_detection();
            }
        }
    }
}

// does the samething as moveSouth, except for east direction
void HUMania::moveEast()
{
    if(level_snake==1)
    {
        snake_lvl_1.draw();
        snake_lvl_1.moveE();
        if(v==true)
        {
            v = false;
            count++;
        }
        else
        {   
            if(count<5)
            {
                count++;
            }
            else
            {
                count = 0;
                collision_detection();
            }
        }
    }
    else if(level_snake==2)
    {
        snake_lvl_2.draw();
        snake_lvl_2.moveE();
        if(v==true)
        {
            v = false;
            count++;
        }
        else
        {   
            if(count<5)
            {
                count++;
            }
            else
            {
                count = 0;
                collision_detection();
            }
        }
    }
    else
    {
        snake_lvl_3.draw();
        snake_lvl_3.moveE();
        if(v==true)
        {
            v = false;
            count++;
        }
        else
        {   
            if(count<5)
            {
                count++;
            }
            else
            {
                count = 0;
                collision_detection();
            }
        }
    }
}

// defining Create apple
void HUMania::CreateApple() 
{
    x = rand() % 950; // making sure it is within the screen
    y = rand() % 550; // making sure it is within the screen
    Apple* a = new Apple(x,y);
    apples.push_back(a);
}

// Defining drawing apple
void HUMania::DrawApple()
{
    for(int i=0;i<apples.size();i++)
    {
        apples[i]->draw();
    }
}

// defining create grape
void HUMania::CreateGrape()
{
    a = rand() % 950; // making sure within the screen
    b = rand() % 550; // making sure within the screen
    Grape* g = new Grape(a,b);
    grapes.push_back(g);
}

// defining drawing grape
void HUMania::DrawGrape()
{
    for(int h=0;h<grapes.size();h++)
    {
        grapes[h]->draw();
    }
}

// defining collision detection
// Checks for collision between the apple or grape appearing on the screen with the snake's head
// if both are in contact, the apple or grape with be detected and removed from the screen
// else they will keep on appearing on the screen
void HUMania::collision_detection()
{
    //cout << "Score" << score << "\n";
    if(level==1 && sequence==2)
    {
        if(((snake_lvl_1.moverRect.x<=apples[0]->moverRect.x+80) && (snake_lvl_1.moverRect.x>=apples[0]->moverRect.x-80)) && ((snake_lvl_1.moverRect.y<=apples[0]->moverRect.y+80) && (snake_lvl_1.moverRect.y>=apples[0]->moverRect.y-80)))
        {
            v = true;
            count++;
            sequence++;
            apples.erase(apples.begin());
            CreateGrape();
            DrawGrape();
            level++;
            counter = counter + 1;
            score = score_op + counter;
        }
    }
    else if(level==1 && sequence!=2)
    {
        if(((snake_lvl_1.moverRect.x<=apples[0]->moverRect.x+80) && (snake_lvl_1.moverRect.x>=apples[0]->moverRect.x-80)) && ((snake_lvl_1.moverRect.y<=apples[0]->moverRect.y+80) && (snake_lvl_1.moverRect.y>=apples[0]->moverRect.y-80))){
            v = true;
            count++;
            sequence++;
            apples.erase(apples.begin());
            CreateApple();
            DrawApple();
            counter = counter + 1;
            score = score_op + counter;
        }
    }
    else if(level==2 && sequence==5)
    {
        if(((snake_lvl_2.moverRect.x<=apples[0]->moverRect.x+80) && (snake_lvl_2.moverRect.x>=apples[0]->moverRect.x-80)) && ((snake_lvl_2.moverRect.y<=apples[0]->moverRect.y+80) && (snake_lvl_2.moverRect.y>=apples[0]->moverRect.y-80)))
        {
            v = true;
            count++;
            sequence++;
            apples.erase(apples.begin());
            CreateGrape();
            DrawGrape();
            level++;
            counter = counter + 1;
            score = score_op + counter;
        }
    }
    else if(level==2 && sequence==3)
    {
        if(((snake_lvl_1.moverRect.x<=grapes[0]->moverRect.x+80) && (snake_lvl_1.moverRect.x>=grapes[0]->moverRect.x-80)) && ((snake_lvl_1.moverRect.y<=grapes[0]->moverRect.y+80) && (snake_lvl_1.moverRect.y>=grapes[0]->moverRect.y-80))){
            v = true;
            count++;
            sequence++;
            grapes.erase(grapes.begin());
            level_snake++;
            CreateSnake();
            CreateApple();
            DrawApple();
        }
    }
    else if(level==2 && sequence>3 && sequence<5)
    {
        if(((snake_lvl_2.moverRect.x<=apples[0]->moverRect.x+80) && (snake_lvl_2.moverRect.x>=apples[0]->moverRect.x-80)) && ((snake_lvl_2.moverRect.y<=apples[0]->moverRect.y+80) && (snake_lvl_2.moverRect.y>=apples[0]->moverRect.y-80))){
            v = true;
            count++;
            sequence++;
            apples.erase(apples.begin());
            CreateApple();
            DrawApple();
            counter = counter + 1;
            score = score_op + counter;
        }
    }
    else if(level==3 && sequence==6)
    {
        if(((snake_lvl_2.moverRect.x<=grapes[0]->moverRect.x+80) && (snake_lvl_2.moverRect.x>=grapes[0]->moverRect.x-80)) && ((snake_lvl_2.moverRect.y<=grapes[0]->moverRect.y+80) && (snake_lvl_2.moverRect.y>=grapes[0]->moverRect.y-80))){
            v = true;
            count++;
            sequence++;
            grapes.erase(grapes.begin());
            level_snake++;
            CreateSnake();
            CreateApple();
            DrawApple();
        }
    }
    else
    {
        if(((snake_lvl_3.moverRect.x<=apples[0]->moverRect.x+80) && (snake_lvl_3.moverRect.x>=apples[0]->moverRect.x-80)) && ((snake_lvl_3.moverRect.y<=apples[0]->moverRect.y+80) && (snake_lvl_3.moverRect.y>=apples[0]->moverRect.y-80))){
            v = true;
            count++;
            sequence++;
            apples.erase(apples.begin());
            CreateApple();
            DrawApple();
            counter = counter + 1;
            score = score_op + counter;
        }
    }
}
