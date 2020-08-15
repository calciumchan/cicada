//this file should contain declarations of all the drawing functions
//the functions source code should be seperated per function like draw_clear.cpp draw_line.cpp

#pragma once

#include "meta.h"

//flip variables
extern char flip_none, flip_h, flip_v, flip_both;

//set the color
void draw_set_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

//thses 2 functions are mostly useful for our drawing code so we dont have to write the huge lines of garbage
void draw_set_scale();
void draw_reset_scale();

//clipping
void draw_set_clip(int x, int y, int w, int h);
void draw_reset_clip();

//viewport
//this seems a little borked right now, needs work
void draw_set_viewport(int x, int y, int w, int h);
void draw_reset_viewport();

//draw normal stuff
void draw_clear();
void draw_point(int x, int y);
void draw_line(int x, int y, int x2, int y2);
void draw_ellipse(int x, int y, int x2, int y2);
void draw_circle(int x, int y, int radius); //ive always wanted this, please dear god let me have this
void draw_rectangle(int x, int y, int x2, int y2);

void draw_spritesheet(ce_spritesheet spritesheet, int x, int y);//these need to be fixed up once i have a sprite class and w/e
void draw_sprite(ce_spritesheet spritesheet, int x, int y, int w, int h, int srcx, int srcy);
void draw_sprite_ex(ce_spritesheet spritesheet, int x, int y, int w, int h, int srcx, int srcy, int srcw, int srch, double angle, char flip);
//all of this might get changed later, i have no idea if this is optimal so ill come back to it later
