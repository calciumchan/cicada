//main source file
#include "cicada.h"
#include "math.h"

int main( int argc, char* args[] ){
	//cicada_start() should be run at the beginning of all programs
	cicada_start();
	//window stuff for testing
	cicada_set_theme("testtheme");
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
		testwindow.set_scale(random_range(5,10));
		int srcx = random((tex_mado.get_w()-32)/32)*32;
		int srcy = random((tex_mado.get_h()-32)/32)*32;
		for(int i = 0; i < testwindow.get_ws(); i+=16){
			for(int j = 0; j < testwindow.get_hs(); j+=16){
				draw_sprite(tex_mado,i,j,16,16,srcx,srcy);
			}
		}
		draw_reset_clip();
		draw_set_viewport(fmod(g_ticks,300),0,300,300);
		testwindow.set_scale(-1);
		int drawx = (testwindow.get_ws()/2)-(testtexture.get_w()/2);
		int drawy = (testwindow.get_hs()/2)-(testtexture.get_h()/2);
		draw_spritesheet(testtexture,drawx,drawy);

		draw_sprite(testtexture, 32, 0, 32, 32, 0, 0);
		draw_sprite_ex(testtexture,0,0,128,128,0,0,32,32,g_ticks,flip_none);
		
		draw_reset_viewport();
		testwindow.set_scale(1);
		draw_spritesheet(tex_mado,0,0);

		testwindow.draw();
		cicada_draw();
	}
	testwindow.end();
}
