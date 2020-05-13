#include "draw.h"

void draw_point(int x, int y){
	SDL_RenderDrawPoint(g_focusedwindow -> main_renderer, x, y);
}
