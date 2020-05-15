#include "spritesheet.h"

ce_spritesheet :: ce_spritesheet(){
	name = "";
	scale = 1;
	themeable = true;
	w = 0;
	h = 0;
	texture = NULL;
}

void ce_spritesheet :: import(){
	texture = import_sprite(name);
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
}

void ce_spritesheet :: set_name(std::string _name){
	name = _name;
}

int ce_spritesheet :: get_w(){ return w;}
int ce_spritesheet :: get_h(){ return h;}
