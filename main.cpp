//main source file
#include "cicada.h"

int main( int argc, char* args[] ){
	//cicada_start() should be run at the beginning of all programs
	cicada_start();
	//window stuff for testing
	cicada_set_theme("testtheme");
	ce_window testwindow(300,300,100,100);
	testwindow.start();
	testwindow.set_focus();
	testwindow.set_resizable(true);
	testwindow.set_scale(-1);
	//texture stuff
	ce_spritesheet testtexture;
	testtexture.set_name("testtext");
	testtexture.import();
	while(cicada_quit() == false){
		cicada_step();
		testwindow.step();
		draw_set_color(255, 255, 255, 255);
		draw_clear();
		draw_set_color(0, 0, 0, 100);
		//mouse test
		if(get_mouse_pressed(mb_left)){
			draw_line(get_mouse_x(), get_mouse_y(), get_mouse_xp(), get_mouse_yp());
			draw_line(get_mouse_x(),get_mouse_y(),get_mouse_xlc(),get_mouse_ylc());
		}
		//draw sprite centered
		int drawx = (testwindow.get_ws()/2)-(testtexture.get_w()/2);
		int drawy = (testwindow.get_hs()/2)-(testtexture.get_h()/2);
		draw_spritesheet(testtexture,drawx,drawy);
		int offset = sin(g_ticks/32)*32;
		draw_sprite(testtexture, 0, 0, offset, 32, 0, 0, 32, 32);
		testwindow.draw();
		cicada_draw();
	}
	testwindow.end();
}
