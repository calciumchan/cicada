//this class lumps the SDL window and renderer into one class and streamlines things a bit
//this should make it easier to have multiple windows and keep things the right size
//needs a lot of work and functions added, kinda barebones rn
//the scale functions are probably my favorite part of this

#pragma once
#include "meta.h"

class ce_window{
	public:
	ce_window(int _set_w, int _set_h, int _min_w, int _min_h);
	void start();
	void end();
	void step();
	void draw();
	void set_scale(int _scale);
	int get_scale();
	void set_resizable(bool _resizable);
	int get_w();
	int get_h();
	int get_ws();
	int get_hs();
	void set_focus();
	SDL_Window * main_window;
	SDL_Renderer * main_renderer;
	
	private:
	int w, h, min_w, min_h, set_w, set_h;
	bool active;
	bool resizable;
	int scale;
};
