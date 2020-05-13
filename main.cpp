//main source file
#include "cicada.h"

int main( int argc, char* args[] ){
	cicada_start();
	ce_window testwindow;
	ce_window multiwindow;
	testwindow.start();
	testwindow.set_focus();
	draw_set_color(255, 255, 255, 255);
	draw_clear();
	while(cicada_quit() == false){

		draw_set_color(0, 0, 0, 100);
		for(int i = 0; i<500; i++){
			draw_point(rand()%300,rand()%300);
		}
		testwindow.draw();
		cicada_step();
		cicada_draw();
	}
	testwindow.end();
}
