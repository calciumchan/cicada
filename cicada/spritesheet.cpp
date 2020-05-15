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
	//im going to replace the import function because reasons
	//texture = import_sprite(name);
	//set the path to base
	std::string path = std::string("base/") + name + std::string(".png"); 
	//load in the surface
	SDL_Surface * loadedsurface = IMG_Load( path.c_str() );
	//create the texture from the surface
	texture = SDL_CreateTextureFromSurface(g_focusedwindow -> main_renderer, loadedsurface);
	SDL_FreeSurface(loadedsurface);
	loadedsurface = NULL;
	//get the height and width of the base texture
	//d_w and d_h are the default heights and widths. will be useful in a bit
	SDL_QueryTexture(texture, NULL, NULL, &d_w, &d_h);
	//load in the theme texture if themeable is true
	if(themeable == true){
		//load theme
		path = std::string("themes/") + g_theme + std::string("/") + name + std::string(".png");
		loadedsurface = IMG_Load( path.c_str() );
		//if the theme exists then import it as the texture
		if(loadedsurface != NULL){
			SDL_DestroyTexture(texture);
			texture = SDL_CreateTextureFromSurface(g_focusedwindow -> main_renderer, loadedsurface);
		}
		SDL_FreeSurface(loadedsurface);
		loadedsurface = NULL;
	}
	//get the heigt and width
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	//set the scale
	scale = w / d_w;
	//were going to use the scale when drawing to the screen
	//that way we can import textures that are of a higher resolution and display them at the same size
	//this is a bit rough, we might want to add some checks that make sure the theme file is an even scale
}

void ce_spritesheet :: set_name(std::string _name){
	name = _name;
}

int ce_spritesheet :: get_w(){ return d_w;}
int ce_spritesheet :: get_h(){ return d_h;}

int ce_spritesheet :: get_realw(){ return w;}
int ce_spritesheet :: get_realh(){ return h;}

int ce_spritesheet :: get_scale(){ return scale;}
