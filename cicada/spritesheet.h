//this is the header file for sprite sheets
//sprite sheets should be able to check to see if there is a file by the same name in the themes folder
//if there is a file with the same name in the themes folder it should use that instead
//if the loaded file is a different size than the base file we check the size factor
//we use the size factor when drawing, thus allowing for higher or lower quality sprites
//i think this is a really cool feature, and i want it baked right into the engine
//that way anything that i make with the engine will have at least basic mod support
//this same philosophy should carry over to sounds and other assets as well

#pragma once
#include "meta.h"
#include <string>

class ce_spritesheet{
	public:
	ce_spritesheet();
	void import();
	void set_name(std::string _name);
	std::string get_name();
	void set_themeable( bool _themeable );
	int get_width();
	int get_height();
	int get_scale();
	SDL_Texture * texture;
	private:
	int w,h;
	int scale;
	bool themeable;//if the sheet can be loaded from a theme
	std::string name;
};
