//these are functions that will be called by the user in main.cpp, they run the show
//please tell me this is a good way of doing this
//i have no fucking clue if this will work out the way i want
//im going to try replacing the handle with this
//g_ denotes a global variable

#pragma once

#include "meta.h"

extern bool g_quit;
extern int g_framerate;
extern SDL_Event g_event;

void cicada_start();
void cicada_step();
void cicada_draw();
bool cicada_quit();
