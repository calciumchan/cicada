#include "window.h"

window :: window(){}

void window :: start(){
	SDL_CreateWindowAndRenderer(300,300,0,&main_window,&main_renderer);
}
