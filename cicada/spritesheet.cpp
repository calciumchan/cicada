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
	texture = import_sprite("testtext.png");
}

void ce_spritesheet :: set_name(std::string _name){
	name = _name;
}
