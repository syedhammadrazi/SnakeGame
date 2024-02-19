#include "score.hpp"

// Operator Overloading
Score Score::operator + (int num)
{  
    Score res;
    res.score_opt = score_opt + num;
    return res;
}

void Score::showScore()
{
	cout << score_opt << "\n";

    TTF_Init();
	TTF_Font* font = TTF_OpenFont("Nasa21-l23X.ttf",20);
    SDL_Color  colour = {0, 0, 0, 0};
	string top = "S " + to_string(score_opt);
	string mess = "hello world";
	SDL_Surface *surface_message = TTF_RenderText_Solid(font,top.c_str(),colour);
	SDL_Texture *message = SDL_CreateTextureFromSurface(Drawing::gRenderer,surface_message);
	SDL_Rect message_rect = {20,20,200,50};
	SDL_RenderCopy(Drawing::gRenderer,message,NULL,&message_rect);	
	SDL_FreeSurface(surface_message);
	SDL_DestroyTexture(message);
	TTF_CloseFont(font);
	TTF_Quit();
}