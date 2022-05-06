#include "cicada.h"

int main(){
	cicada_start();
	gamepad_open_all();
	while(!is_cicada_quit()){
		cicada_step();
		window_clear_all();

		if(gamepad_get_button(0,0)){
			draw_sprite_hud_ex("test",0,96,0,0,128,128,32,32,get_tick(),64,64,0,0);
			draw_sprite_hud_ex("test",0,32,0,0,64,64,32,32,0,0,0,1,0);
			draw_sprite_hud_ex("test",64,32,0,0,64,64,32,32,0,0,0,0,0);
			draw_sprite_hud_ex("test",128,32,0,0,64,64,32,32,get_tick(),32,32,0,0);
			draw_sprite_hud("test",0,0,0,0,32,32);
			draw_sprite_hud_rotate("test",32,0,0,0,32,32,get_tick(),16,16);
		}

		draw_sprite_hud("test",
			(get_window_w()/2) + (gamepad_get_leftx(0)/100),
			(get_window_h()/2) + (gamepad_get_lefty(0)/100),
		0,0,32,32);
		draw_sprite_hud_stretch("test",(get_window_w()/2)-((gamepad_get_triggerr(0)/100)/2),(get_window_h()/2)-((gamepad_get_triggerl(0)/100)/2),0,0,gamepad_get_triggerr(0)/100,gamepad_get_triggerl(0)/100,32,32);

		cicada_draw();
		SDL_Delay(1000/60);
	}
	cicada_end();
	return 0;
}