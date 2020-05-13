#include "draw.h"

void draw_line(int x, int y, int x2, int y2){
	//this is super basic
	//i need to come back later and make a proper line algorithm
	SDL_RenderDrawLine(g_focusedwindow -> main_renderer, x, y, x2, y2);
}
