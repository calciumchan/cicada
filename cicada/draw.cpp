//im going to merge all the drawing code into one source file
//i realized im kind of retarded and having all these like 3 line files be seperate is obnoxious

#include "draw.h"

//flip variables
char flip_none = 'a';
char flip_h = 'b';
char flip_v = 'c';
char flip_both = 'd';

//set the color
void draw_set_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a){
	SDL_SetRenderDrawColor(g_focusedwindow -> main_renderer, r, g, b, a);
}

//functions for scale
void draw_set_scale(){
	SDL_RenderSetScale(g_focusedwindow -> main_renderer, g_focusedwindow -> get_scale(), g_focusedwindow -> get_scale());
}

void draw_reset_scale(){
	SDL_RenderSetScale(g_focusedwindow -> main_renderer, 1, 1);
}

//clipping
void draw_set_clip(int x, int y, int w, int h){
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_RenderSetClipRect(g_focusedwindow -> main_renderer, &rect);
}
void draw_reset_clip(){
	SDL_RenderSetClipRect(g_focusedwindow -> main_renderer, NULL);
}

//viewport
void draw_set_viewport(int x, int y, int w, int h){
	SDL_Rect rectviewport;
	rectviewport.x = x;
	rectviewport.y = y;
	rectviewport.h = h;
	rectviewport.w = w;
	SDL_RenderSetViewport(g_focusedwindow -> main_renderer, &rectviewport);
}
void draw_reset_viewport(){
	SDL_RenderSetViewport(g_focusedwindow -> main_renderer, NULL);
}

//normal drawing
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
	int win_scale = g_focusedwindow -> get_scale();
	int spr_scale = spritesheet.get_scale();
	//set p the rectangle to point to where to draw
	SDL_Rect rect_screen;
	rect_screen.x = x * win_scale;
	rect_screen.y = y * win_scale;
	//query the texture to get the right width and everything
	rect_screen.w = spritesheet.get_w() * win_scale;
	rect_screen.h = spritesheet.get_h() * win_scale;
	//draw to the screen
	SDL_RenderCopy(g_focusedwindow -> main_renderer, spritesheet.texture, NULL, &rect_screen);
}

void draw_sprite(ce_spritesheet spritesheet, int x, int y, int w, int h, int srcx, int srcy){
	//get the scale
	int win_scale = g_focusedwindow -> get_scale();
	int spr_scale = spritesheet.get_scale();
	//get a rect for where to draw on the screen
	SDL_Rect rect_screen;
	rect_screen.x = x * win_scale;
	rect_screen.y = y * win_scale;
	rect_screen.w = w * win_scale;
	rect_screen.h = h * win_scale;
	//get a rect for what part of the sheet to draw from
	SDL_Rect rect_source;
	rect_source.x = srcx * spr_scale;
	rect_source.y = srcy * spr_scale;
	rect_source.w = w * spr_scale;
	rect_source.h = h * spr_scale;
	//draw to the screen
	SDL_RenderCopy(g_focusedwindow -> main_renderer, spritesheet.texture, &rect_source, &rect_screen);
}

void draw_sprite_ex(ce_spritesheet spritesheet, int x, int y, int w, int h, int srcx, int srcy, int srcw, int srch, double angle, char flip){
	//get the scale
	int win_scale = g_focusedwindow -> get_scale();
	int spr_scale = spritesheet.get_scale();
	//get a rect for where to draw on the screen
	SDL_Rect rect_screen;
	rect_screen.x = x * win_scale;
	rect_screen.y = y * win_scale;
	rect_screen.w = w * win_scale;
	rect_screen.h = h * win_scale;
	//get a rect for what part of the sheet to draw from
	SDL_Rect rect_source;
	rect_source.x = srcx * spr_scale;
	rect_source.y = srcy * spr_scale;
	rect_source.w = w * spr_scale;
	rect_source.h = h * spr_scale;
	//set up flip
	SDL_RendererFlip srcflip;
	switch(flip){
		case 'a':
			srcflip = SDL_FLIP_NONE;
			break;
		case 'b':
			srcflip = SDL_FLIP_HORIZONTAL;
			break;
		case 'c':
			srcflip = SDL_FLIP_VERTICAL;
			break;
		case 'd':
			//i have no idea why this doesnt work
			//SDL_RendererFlip rcflip = SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL;
			break;
	}
	//actually draw to the screen
	SDL_RenderCopyEx(g_focusedwindow -> main_renderer, spritesheet.texture, &rect_source, &rect_screen, angle, NULL, srcflip);
}
