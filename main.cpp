//main source file
#include "cicada.h"
int main( int argc, char* args[] ){
	cicada_start();
	ce_window testwindow;
	testwindow.start();
	while(cicada_quit() == false){
		cicada_step();
		cicada_draw();
		testwindow.draw();
		SDL_Delay(1000/30);
	}
	testwindow.end();
}
