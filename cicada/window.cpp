#include "window.h"

ce_window :: ce_window(){
	//active flag
	active=false;
	//the base scale
	scale = 1;
	//set some size parameters
	set_w = 640;
	set_h = 360;
	min_w = set_w;
	min_h = set_h;
	w = set_w;
	h = set_h;
	//resizable flag
	resizable = false;
}

void ce_window :: start(){
	//create the window and renderer and set the active flag
	SDL_CreateWindowAndRenderer(set_w,set_h,0,&main_window,&main_renderer);
	bool active=true;
}

void ce_window :: step(){
	//this gets the window size
	SDL_GetWindowSize(main_window, &w, &h);
	//set the window size if its too small
	if( w < min_w ){
		SDL_SetWindowSize(main_window, min_w, h);
	}
	if( h < min_h ){
		SDL_SetWindowSize(main_window, w, min_h);
	}
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
		//set the scale automatically based on the windows size
		//first we make sure that the window size isnt below the default
		//set_w and set_h are the defaults so we use those to set the automatic scale
		if( w < set_w || h < set_h){
			return 1;
		}else if( w < h ){
			return w/set_w;
		}else{
			return h/set_h;
		}
	}else{
		return scale;
	}
}

void ce_window :: set_resizable(bool _resizable){
	//im using an ifelse because SDL wants an SDL_BOOL instead of a bool????
	if( _resizable == true){
		SDL_SetWindowResizable(main_window, SDL_TRUE);
	}else{
		SDL_SetWindowResizable(main_window, SDL_FALSE);
	}
}

int ce_window :: get_width(){ return w; }
int ce_window :: get_height(){ return h; }
