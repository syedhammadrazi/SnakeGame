#include "game.hpp"
using namespace std;

int main(int argc, char* argv[])
{

    // (pointer) Object of class game #06
    // Design patter singleton #01 
    Game* game = Game::Instance();
    srand(time(NULL));
    if (!game->init())
    {
        printf ("Failed to initialize! \n");
        return 0;
    }

    // Main Menu
    if (!game->load_mainMenu())
    {
        printf ("Failed to load media! \n");
        return 0;
    }

    game->run(); // calling game.run
    game->close(); // calling game.close

    return 0;
}