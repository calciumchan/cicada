#include "cicada.h"

int main(){
	start();
	window_open("preview","previwe");
	while(!is_cicada_quit()){
		window_clear_all();
		if(rand()%10 == 1){
			window_set_target("preview");
		}else{
			window_set_target("main");
		}
		draw_sprite_hud("test",32,32,0,0,512,512);
		step();
		SDL_Delay(1);
	}
	end();
	return 0;
}