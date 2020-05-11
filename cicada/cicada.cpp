#include "cicada.h"
#include "handle.h"

bool g_quit = false;
SDL_Event g_event;

void cicada_start(){

}

void cicada_step(){
	while(SDL_PollEvent( &g_event ) != 0 ){
		if( g_event.type = SDL_QUIT ){
			g_quit = true;
		}
	}
}

void cicada_draw(){
	
}

bool cicada_quit(){
	return g_quit;
}
