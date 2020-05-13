#include "draw.h"

void draw_clear(){
	SDL_RenderClear(g_focusedwindow -> main_renderer);
}
