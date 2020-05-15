//main source file
#include "cicada.h"

int main( int argc, char* args[] ){
	//cicada_start() should be run at the beginning of all programs
	cicada_start();
	//window stuff for testing
	ce_window testwindow(300,300,100,100);
	testwindow.start();
	testwindow.set_focus();
	testwindow.set_resizable(true);
	testwindow.set_scale(-1);
	ce_spritesheet testtexture;
	testtexture.set_name("testtext.png");
	testtexture.import();
	while(cicada_quit() == false){
		cicada_step();
		testwindow.step();
		draw_set_color(255, 255, 255, 255);
		draw_clear();
		draw_set_color(0, 0, 0, 100);
		if(testtexture.texture == NULL){
			draw_line(0,0,testwindow.get_ws()/2,testwindow.get_hs()/2);
		}
		draw_spritesheet(testtexture,0,0);
		testwindow.draw();
		cicada_draw();
	}
	testwindow.end();
}
