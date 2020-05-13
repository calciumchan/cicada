#include "window.h"

ce_window :: ce_window(){
	//active flag
	active=false;
	//the base scale
	scale = 1;
	//set some size parameters
	set_w = 360;
	set_h = 640;
	min_w = set_w;
	min_h = set_h;
	w = set_w;
	h = set_h;
}

void ce_window :: start(){
	//create the window and renderer and set the active flag
	SDL_CreateWindowAndRenderer(300,300,0,&main_window,&main_renderer);
	bool active=true;
}

void ce_window :: step(){
	//this gets the window size
	SDL_GetWindowSize(main_window, &w, &h);
}

void ce_window :: draw(){
	//draw to the screen
	SDL_RenderPresent(main_renderer);
}

void ce_window :: end(){
	//destroy the window and the renderer and set their pointers to NULL
	SDL_DestroyWindow(main_window);
	main_window = NULL;
	SDL_DestroyRenderer(main_renderer);
	main_renderer = NULL;
	bool active = false;
}

void ce_window :: set_focus(){
	//this should set the focus of drawing functions to be this window
	//g_focusedwindow should be used when drawing, i hope this works
	g_focusedwindow = this;
}

void ce_window :: set_scale(int _scale){
	if( _scale == 0 || _scale < -1){
		//make sure the scale cant be 0, because thats a bad fucking idea
		scale = 1;
	}else{
		//set the scale
		scale = _scale;
	}
}

int ce_window :: get_scale(){
	if( scale == -1 ){
		return std::min(1,5);
	}else{
		return scale;
	}
}
