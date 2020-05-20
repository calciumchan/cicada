//main source file
#include "cicada.h"

int main( int argc, char* args[] ){
	//cicada_start() should be run at the beginning of all programs
	cicada_start();
	//window stuff for testing
	//cicada_set_theme("testtheme");
	ce_window testwindow(300,300,100,100);
	testwindow.start();
	testwindow.set_focus();
	testwindow.set_resizable(true);

	//texture stuff
	ce_spritesheet testtexture;
	testtexture.set_name("testtext");
	testtexture.import();

	//import another texture  because i want to test stuff
	ce_spritesheet tex_mado;
	tex_mado.set_name("mado");
	tex_mado.import();

	while(cicada_quit() == false){
		cicada_step();
		testwindow.step();
		//test clipping
		draw_set_clip(0,0,m_x,m_y);
		//set the color and clear because reasons
		draw_set_color(255, 255, 255, 255);
		draw_clear();
		draw_set_color(0, 0, 0, 100);
		//mouse test
		if(get_mouse_pressed(mb_left)){
			draw_line(get_mouse_x(), get_mouse_y(), get_mouse_xp(), get_mouse_yp());
			draw_line(get_mouse_x(),get_mouse_y(),get_mouse_xlc(),get_mouse_ylc());
		}
		//draw sprite centered
		testwindow.set_scale(random(10));
		int srcx = random((tex_mado.get_w()-32)/32)*32;
		int srcy = random((tex_mado.get_h()-32)/32)*32;
		for(int i = 0; i < testwindow.get_ws(); i+=16){
			for(int j = 0; j < testwindow.get_hs(); j+=16){
				draw_sprite(tex_mado,i,j,16,16,srcx,srcy);
			}
		}
		testwindow.set_scale(-1);
		int drawx = (testwindow.get_ws()/2)-(testtexture.get_w()/2);
		int drawy = (testwindow.get_hs()/2)-(testtexture.get_h()/2);
		draw_spritesheet(testtexture,drawx,drawy);
		int offset = sin(g_ticks/32)*32;
		draw_sprite(testtexture, 32, 0, 32, 32, 0, 0);
		draw_sprite_ex(testtexture,0,0,128,128,0,0,32,32,offset,flip_none);

		testwindow.draw();
		cicada_draw();
	}
	testwindow.end();
}
