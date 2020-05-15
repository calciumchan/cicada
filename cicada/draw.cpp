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

void draw_ellipse(int x, int y, int x2, int y2){}

void draw_circle(int x, int y, int radius){}

void draw_rectangle(int x, int y, int x2, int y2){}

void draw_spritesheet(ce_spritesheet spritesheet, int x, int y){
	//get the scale
	int scale = g_focusedwindow -> get_scale();
	//set p the rectangle to point to where to draw
	SDL_Rect rect_screen;
	rect_screen.x = x * scale;
	rect_screen.y = y * scale;
	//query the texture to get the right width and everything
	SDL_QueryTexture(spritesheet.texture, NULL, NULL, &rect_screen.w, &rect_screen.h);
	rect_screen.w *= scale;
	rect_screen.h *= scale;
	//draw to the screen
	SDL_RenderCopy(g_focusedwindow -> main_renderer, spritesheet.texture, NULL, &rect_screen);
}

void draw_sprite(ce_spritesheet spritesheet, int x, int y, int w, int h, int srcx, int srcy, int srcw, int srch){
	//get the scale
	int scale = g_focusedwindow -> get_scale();
	//get a rect for where to draw on the screen
	SDL_Rect rect_screen;
	rect_screen.x = x * scale;
	rect_screen.y = y * scale;
	rect_screen.w = w * scale;
	rect_screen.h = h * scale;
	//get a rect for what part of the sheet to draw from
	SDL_Rect rect_source;
	rect_source.x = x;
	rect_source.y = y;
	rect_source.w = w;
	rect_source.h = h;
	//draw to the screen
	SDL_RenderCopy(g_focusedwindow -> main_renderer, spritesheet.texture, &rect_source, &rect_screen);
}
