//these are functions that will be called by the user in main.cpp, they run the show
//please tell me this is a good way of doing this
//i have no fucking clue if this will work out the way i want
//im going to try replacing the handle with this
//g_ denotes a global variable
//im going to replace meta.h and classes.h with this one file, and then rename this to meta.h


#pragma once

//include everything SDL related
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

//declare any and all clases we use here, anything with ce_
class ce_window;
class ce_spritesheet;//this still needs to be defined somewhere

//include all the files in this folder
//fuck it well just use this as the main include i guess
#include "window.h"
#include "draw.h"
#include "spritesheet.h"
#include "math.h"

//global variables
extern bool g_quit;
extern int g_tickrate;
extern int g_framelimit;
extern SDL_Event g_event;
extern ce_window * g_focusedwindow;

void cicada_start();
void cicada_step();
void cicada_draw();
bool cicada_quit();
void cicada_log();//not done, idk if this is worth it
