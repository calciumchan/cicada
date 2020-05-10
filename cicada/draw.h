//this file should contain declarations of all the drawing functions
//the functions source code should be seperated per function like draw_clear.cpp draw_line.cpp

#include "meta.h"

void draw_set_color();

void draw_clear();
void draw_line(int x, int y, int x2, int y2);
void draw_ellipse(int x, int y, int x2, int y2);
void draw_circle(int x, int y, int radius); //ive always wanted this, please dear god let me have this
void draw_rectangle(int x, int y, int x2, int y2);

void draw_sprite(int x, int y);
void draw_spritesheet(int x, int y);//these need to be fixed up once i have a sprite class and w/e
void draw_sprite_ex(int x, int y, int w, int h, int srcx, int srcy, int srcw, int srch);

//all of this might get changed later, i have no idea if this is optimal so ill come back to it later
