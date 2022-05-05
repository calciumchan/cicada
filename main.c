#include "cicada.h"

int main(){
	cicada_start();
	while(!is_cicada_quit()){
		cicada_step();
		window_clear_all();

		draw_sprite_hud_ex("test",0,32,0,0,64,64,32,32,0,0,0,1,0);
		draw_sprite_hud_ex("test",64,32,0,0,64,64,32,32,0,0,0,0,0);
		draw_sprite_hud_ex("test",128,32,0,0,64,64,32,32,get_tick(),32,32,0,0);
		draw_sprite_hud("test",0,0,0,0,32,32);
		draw_sprite_hud_rotate("test",32,0,0,0,32,32,get_tick(),16,16);

		cicada_draw();
		SDL_Delay(1000/60);
	}
	cicada_end();
	return 0;
}