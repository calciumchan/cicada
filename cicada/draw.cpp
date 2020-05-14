//im going to merge all the drawing code into one source file
//i realized im kind of retarded and having all these like 3 line files be seperate is obnoxious

#include "draw.h"

void draw_set_scale(){
	SDL_RenderSetScale(g_focusedwindow -> main_renderer, g_focusedwindow -> get_scale(), g_focusedwindow -> get_scale());
}

void draw_reset_scale(){
	SDL_RenderSetScale(g_focusedwindow -> main_renderer, 1, 1);
}


void draw_set_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a){
	SDL_SetRenderDrawColor(g_focusedwindow -> main_renderer, r, g, b, a);
}

void draw_clear(){
	SDL_RenderClear(g_focusedwindow -> main_renderer);
}

void draw_point(int x, int y){
	draw_set_scale();
	SDL_RenderDrawPoint(g_focusedwindow -> main_renderer, x, y);
	draw_reset_scale();
}

void draw_line(int x, int y, int x2, int y2){
	draw_set_scale();
	SDL_RenderDrawLine(g_focusedwindow -> main_renderer, x, y, x2, y2);
	draw_reset_scale();
}
