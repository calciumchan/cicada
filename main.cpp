//main source file
#include "cicada.h"
int main( int argc, char* args[] ){
	cicada_start();
	ce_window testwindow;
	testwindow.start();
	testwindow.set_focus();
	while(cicada_quit() == false){
		draw_set_color(255, 0, 0, 255);
		draw_clear();
		draw_set_color(0, 0, 0, 255);
		draw_point(10,10);
		cicada_step();
		cicada_draw();
		testwindow.draw();
		SDL_Delay(1000/30);
	}
	testwindow.end();
}
