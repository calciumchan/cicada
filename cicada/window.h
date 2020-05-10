//this class lumps the SDL window and renderer into one class and streamlines things a bit
//this should make it easier to have multiple windows and keep things the right size
//needs a lot of work and functions added, kinda barebones rn
//the scale functions are probably my favorite part of this

#include "meta.h"

class window{
	public:
	window();
	void start();
	void restart();
	void end();
	void step();
	void set_scale(float _scale);
	float get_scale();
	private:
	int w, h, min_w, min_h;
	bool started;
	float scale;
	SDL_Window * main_window;
	SDL_Renderer * main_renderer;
};
