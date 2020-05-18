#include "meta.h"


//define these mother fuckers
bool g_quit = false;
int g_tickrate = 60;
int g_framelimit = 60;
SDL_Event g_event;
ce_window * g_focusedwindow = NULL;
std::string g_theme = "";
double g_ticks = 0;

//SET UP THE MOUSE
int m_x = 0;
int m_y = 0;
int m_xp = 0;
int m_yp = 0;
int m_xlc = -1;
int m_ylc = -1;
int m_xrc = -1;
int m_yrc = -1;
int m_xmc = -1;
int m_ymc = -1;
bool m_rc = false;
bool m_lc = false;
bool m_mc = false;
bool m_rr = false;
bool m_lr = false;
bool m_mr = false;
char mb_left = 'a';
char mb_middle = 'b';
char mb_right = 'c';
char mb_none = 'd';
char mb_any = 'e';


void cicada_start(){
	//init SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);//were only initing PNG files because thats all i care about : )
	//randomize
	srand(10);
	//
}

void cicada_step(){
	//mouse position handling
	m_xp = m_x;
	m_yp = m_y;
	SDL_GetMouseState(&m_x,&m_y);
	//reset the mouse click and release bools
	m_rc = false;
	m_lc = false;
	m_mc = false;
	m_rr = false;
	m_lr = false;
	m_mr = false;

	//event handling
	while( SDL_PollEvent( &g_event ) != 0 ){
		//quit the application
		if( g_event.type == SDL_QUIT ){
			g_quit = true;
		}
		//mouse buttons
		if( g_event.type == SDL_MOUSEBUTTONDOWN){
			switch( g_event.button.button ){
				case SDL_BUTTON_LEFT:
					m_xlc = m_x;
					m_ylc = m_y;
					m_lc = true;
					break;
				case SDL_BUTTON_MIDDLE:
					m_xmc = m_x;
					m_ymc = m_y;
					m_mc = true;
					break;
				case SDL_BUTTON_RIGHT:
					m_xrc = m_x;
					m_yrc = m_y;
					m_rc = true;
					break;
			}
		}
		if( g_event.type == SDL_MOUSEBUTTONUP ){
			switch( g_event.button.button ){
				case SDL_BUTTON_LEFT:
					m_xlc = -1;
					m_ylc = -1;
					m_lr = true;
					break;
				case SDL_BUTTON_MIDDLE:
					m_xmc = -1;
					m_ymc = -1;
					m_mr = true;
					break;
				case SDL_BUTTON_RIGHT:
					m_xrc = -1;
					m_yrc = -1;
					m_rr = true;
					break;
			}
		}
	}
	
	//increment ticks
	g_ticks++;
	
	//delay, this needs to be replaced with a better function later
	SDL_Delay(1000/g_tickrate);
}

void cicada_draw(){
	
}

bool cicada_quit(){
	return g_quit;
}

void cicada_set_theme(std::string _g_theme){
	g_theme = _g_theme;
}

//MOUSE FUNCTIONS
int get_mouse_x(){ return m_x/g_focusedwindow -> get_scale(); }
int get_mouse_y(){ return m_y/g_focusedwindow -> get_scale(); }
int get_mouse_xp(){ return m_xp/g_focusedwindow -> get_scale(); }
int get_mouse_yp(){ return m_yp/g_focusedwindow -> get_scale(); }
int get_mouse_xlc(){ return m_xlc/g_focusedwindow -> get_scale(); }
int get_mouse_ylc(){ return m_ylc/g_focusedwindow -> get_scale(); }
int get_mouse_xmc(){ return m_xmc/g_focusedwindow -> get_scale(); }
int get_mouse_ymc(){ return m_ymc/g_focusedwindow -> get_scale(); }
int get_mouse_xrc(){ return m_xrc/g_focusedwindow -> get_scale(); }
int get_mouse_yrc(){ return m_yrc/g_focusedwindow -> get_scale(); }
//MOUSE BUTTONS
bool get_mouse_pressed(char button){
	if(button == mb_left){ return m_lc; }
	if(button == mb_middle){ return m_mc; }
	if(button == mb_right){ return m_rc; }
	if(button == mb_none){ 
		if(m_lc == false && m_mc == false && m_rc == false){
			return true;
		}else{
			return false;
		}
	}
	if(button == mb_any){ 
		if(m_lc == true || m_mc == true || m_rc == true){
			return true;
		}else{
			return false;
		}
	}
}

void cicada_log(){
	//this will log an output to the terminal maybe, idk if im going to keep this just yet
}
