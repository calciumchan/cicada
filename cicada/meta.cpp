#include "meta.h"


//define these mother fuckers
bool g_quit = false;
int g_tickrate = 60;
int g_framelimit = 60;
SDL_Event g_event;
ce_window * g_focusedwindow = NULL;

void cicada_start(){
	//randomize
	srand(10);
	//
}

void cicada_step(){
	while( SDL_PollEvent( &g_event ) != 0 ){
		if( g_event.type == SDL_QUIT ){
			g_quit = true;
		}
	}
	SDL_Delay(1000/g_tickrate);
}

void cicada_draw(){
	
}

bool cicada_quit(){
	return g_quit;
}
