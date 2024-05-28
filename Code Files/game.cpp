#include "game.hpp"
#include "HUMania.hpp"

using namespace std;

SDL_Renderer* Drawing::gRenderer = NULL;
SDL_Texture* Drawing::assets = NULL;

Game* Game::instance = NULL;
Game::Game(){}
Game* Game::Instance(){
	if(instance == NULL){
		instance = new Game();
	}
	return instance;
}

bool Game::init()
{
    //initialization flag
    bool success = true;

    //initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf ("SDL could not be initialized! SDL Error: %s\n", SDL_GetError());
        success = false;
    }

    else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Xenzia", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( Drawing::gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

bool Game::load_mainMenu()
{
	// Loading success flag
	bool success = true;
	gTexture = loadTexture("snake_page.png");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

bool Game::load_instructions()
{
	// Loading success flag
	bool success = true;
	gTexture = loadTexture("instruction_beta.png");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	
	Drawing::assets = loadTexture("assets.png");
    gTexture = loadTexture("tropic.png");
	if(Drawing::assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	return success;
}

bool Game::load_end()
{
	// Loading success flag
	bool success = true;
	gTexture = loadTexture("End.png");
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(Drawing::assets);
	Drawing::assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( Drawing::gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( Drawing::gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
void Game::run( )
{
	bool quit = false;
	int x = 0;
	SDL_Event e;
	int init2 = Mix_Init(0);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_Music * music = Mix_LoadMUS("snakes.wav");
	Mix_Chunk * sound = Mix_LoadWAV("touch_sound.wav");
    Mix_PlayMusic(music, -1);
	HUMania humania;

	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			else if(e.type == SDL_MOUSEBUTTONDOWN)
			{
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);
				cout << xMouse << "---" << yMouse << endl;

				if (state == 0 && xMouse >= 406 && xMouse <= 603 && yMouse >= 348 && yMouse <= 437)
				{
					state = 2;                    // state 2 is when player clicks on PLAY
					loadMedia();
					SDL_ShowCursor(false);
					cout << "this is load media " << state <<endl;
					humania.CreateSnake();
					humania.CreateApple();
					if (x == 0)
					{
						humania.moveEast();
					}

					if (x == 1)
					{
						humania.moveSouth();
					}

					if (x == 2)
					{
						humania.moveNorth();
					}

					if (x == 3)
					{
						humania.moveWest();
					}

					humania.DrawApple();
				}
				else if (state == 0 && xMouse >= 406 && xMouse <= 603 && yMouse >= 463 && yMouse <= 552)
				{
					state = 1;                   // state 1 is when player clicks on INFO
					load_instructions();
					cout << "this is info " << state << endl;
				}
				else if (state == 1 && xMouse >= 406 && xMouse <= 603 && yMouse >= 463 && yMouse <= 552)
				{
					state = 0;                  // state 0 is when player clicks on MENU from INFO 
					load_mainMenu();
					cout << "this is main menu " <<  state << endl;
				}
			}

			if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_r && state == 3)
			{
				load_mainMenu();
				state = 0;
				SDL_ShowCursor(true);
			}
		
			if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
					case SDLK_DOWN:
						x = 1;
						humania.moveSouth();
						Mix_PlayChannel(-1, sound, 0);
						break;
					case SDLK_UP:
						x = 2;
						humania.moveNorth();
						Mix_PlayChannel(-1, sound, 0);
						break;
					case SDLK_LEFT:
						x = 3;
						humania.moveWest();
						Mix_PlayChannel(-1, sound, 0);
						break;
					case SDLK_RIGHT:
						x = 0;
						humania.moveEast();
						Mix_PlayChannel(-1, sound, 0);
						break;
				}
			}

		}

		SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//********draw the objects here*******

		if(state==2)
		{
			humania.callScore();
			if (x == 0)
			{
				humania.moveEast();
			}

			if (x == 1)
			{
				humania.moveSouth();
			}

			if (x == 2)
			{
				humania.moveNorth();
			}

			if (x == 3)
			{
				humania.moveWest();
			}

			humania.DrawApple();
			humania.DrawGrape();
		}

		//**********************
		if(state == 2 && humania.gameStatus() == false)
		{
			state = 3;
			load_end();
		}

    	SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer
	    SDL_Delay(100);	//causes sdl engine to delay for specified miliseconds
	}
			
}