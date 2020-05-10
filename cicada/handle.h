//this will be the main handler that gets created at the start of the program
//it should handle anyting like step functions, and looping through objects
//should handle input handling as well
//i had a pretty good handler in the last version of this so i might just copy that over

#include "meta.h"

class handle{
	public:
	handle();
	void step();
	void end();

	private:
	SDL_Event e;
};
