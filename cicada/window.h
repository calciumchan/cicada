//this class lumps the SDL window and renderer into one class and streamlines things a bit
//this should make it easier to have multiple windows and keep things the right size
//needs a lot of work and functions added, kinda barebones rn
//the scale functions are probably my favorite part of this

#pragma once
#include "meta.h"

class ce_window{
	public:
	ce_window();
	void start();
	void restart();
	void end();
	void step();
	void draw();
	void set_scale(int _scale); 
	int get_scale();
	int get_width();
	int get_height();
	int get_width_scaled();
	int get_height_scaled();
	void set_focus();
	SDL_Window * main_window;
	SDL_Renderer * main_renderer;
	
	private:
	int w, h, min_w, min_h, set_w, set_h;
	bool active;
	int scale;
};
