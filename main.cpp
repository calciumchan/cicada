//main source file
#include "cicada.h"

int main( int argc, char* args[] ){
	//cicada_start() should be run at the beginning of all programs
	cicada_start();
	//window stuff for testing
	ce_window testwindow;
	ce_window multiwindow;
	testwindow.start();
	testwindow.set_focus();

	while(cicada_quit() == false){
		cicada_step();
		testwindow.step();
		draw_set_color(255, 255, 255, 255);
		draw_clear();
		draw_set_color(0, 0, 0, 100);
		for(int i = 0; i<500; i++){
			draw_point(rand()%testwindow.get_width(),rand()%testwindow.get_height());
		}
		testwindow.draw();
		cicada_draw();
	}
	testwindow.end();
}
