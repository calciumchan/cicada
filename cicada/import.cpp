#include "import.h"

//im going to basically just copy whats done on the lazyfoo tutorial for now
SDL_Texture * import_sprite( std::string path ){
	SDL_Texture * importedtexture = NULL;
	
	if(g_theme != ""){
		path = std::string("themes/") + g_theme + path + std::string(".png");
	}else{
		path = std::string("base/") + path + std::string(".png");
	}


	SDL_Surface * loadedsurface = IMG_Load( path.c_str() );

	importedtexture = SDL_CreateTextureFromSurface( g_focusedwindow -> main_renderer, loadedsurface );

	SDL_FreeSurface(loadedsurface);

	return importedtexture;
}
