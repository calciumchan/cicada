//this will be the main handler that gets created at the start of the program
//it should handle anyting like step functions, and looping through objects
//should handle input handling as well
//i had a pretty good handler in the last version of this so i might just copy that over
#pragma once
#include "meta.h"
#include "window.h"

class ce_handle{
	public:
	ce_handle();
	void step();
	void end();
	ce_window * focusedwindow;
	bool quit;
	
	private:
	SDL_Event e;
};
