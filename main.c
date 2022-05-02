#include "cicada.h"

struct player{
	int y,vely;
} player;

char gameover = 0;
int bgscroll;

int main(){
	cicada_start();
	while(!is_cicada_quit()){
		cicada_step();
		window_clear_all();

		//TEST
		if(gameover == 0){
			player.vely ++;
		}
		if(player.y >= get_window_h()-32){
			gameover = 1;
			player.y = get_window_h()-32;
		}
		if(player.y <= 0){
			gameover = 1;
			player.y = 0;
		}
		if(key_check_pressed(SDLK_a) && gameover == 0){
			player.vely = -16;
		}else if(key_check_pressed(SDLK_a) && gameover == 1){
			gameover = 0;
			player.y = get_window_h()/2;
			player.vely = -16;
		}
		if(gameover == 0){
			player.y += player.vely;
		}
		draw_sprite_hud("test",128,player.y,0,0,32,32);
		//TEST

		cicada_draw();
		SDL_Delay(1000/60);
	}
	cicada_end();
	return 0;
}