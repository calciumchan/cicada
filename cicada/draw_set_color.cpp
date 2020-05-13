#include "draw.h"

void draw_set_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a){
	SDL_SetRenderDrawColor(g_focusedwindow -> main_renderer, r, g, b, a);
}
