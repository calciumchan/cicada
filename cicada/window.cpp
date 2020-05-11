#include "window.h"

ce_window :: ce_window(){}

void ce_window :: start(){
	SDL_CreateWindowAndRenderer(300,300,0,&main_window,&main_renderer);
}

void ce_window :: draw(){
	SDL_RenderPresent(main_renderer);
}

void ce_window :: end(){
	//destroy the window and the renderer and set their pointers to NULL
	SDL_DestroyWindow(main_window);
	main_window = NULL;
	SDL_DestroyRenderer(main_renderer);
	main_renderer = NULL;
}
