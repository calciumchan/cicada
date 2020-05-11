#include "handle.h"

ce_handle :: ce_handle(){}

void ce_handle :: step(){
	//this is crap that happens every frame, should probably loop through objects and whatnot
	
	//get some input
	//come back to this later and make a full key state handler
	//right now im just goint to add a close function so that testing is easier
	while(SDL_PollEvent( &e )){
		if( e.type = SDL_QUIT ){
			quit = true;
		}
	}
}
