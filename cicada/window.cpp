#include "window.h"

ce_window :: ce_window(){}

void ce_window :: start(){
	SDL_CreateWindowAndRenderer(300,300,0,&main_window,&main_renderer);
}
