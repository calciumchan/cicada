/*----------------------------------------------------------------------------------------------------
|
|	INCLUDES
|
----------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

/*----------------------------------------------------------------------------------------------------
|
|	GLOBAL VARS
|
----------------------------------------------------------------------------------------------------*/
SDL_Event cicada_event;

/*----------------------------------------------------------------------------------------------------
|
|	STRUCTS
|
----------------------------------------------------------------------------------------------------*/
struct cicada_engine_struct{
	int quit, render_target, render_target_is_texture;
} cicada_engine;

int cicada_window_max = 20;
struct cicada_window_struct{
	SDL_Window *window;
	SDL_Renderer *renderer;
	char *id[10];
	char *title[50];
	int open,w,h;
} *cicada_window;

int cicada_sprite_max = 1000;
int cicada_sprite_count = 0;
struct cicada_sprite_struct{
	SDL_Texture *texture;
	int loaded,important,w,h;
	char *name[30];
} *cicada_sprite;

int cicada_key_max = 200;
struct cicada_key_struct{
	int keysym,pressed;
} *cicada_key;

int cicada_setting_max = 500;
struct cicada_setting_struct{
	char *id[20];
	int value,min,max;
} *cicada_setting;

/*----------------------------------------------------------------------------------------------------
|
|	SYSTEM
|
----------------------------------------------------------------------------------------------------*/
void start(){
	printf("CICADA ENGINE!\n  ,_  _  _,\n    \\o-o/\n   ,(.-.),\n _/ |) (| \\_\n   /\\=-=/\\\n  ,| \\=/ |,\n_/ \\  |  / \\_\n    \\_!_/ JGS\nMy hopes and dreams rest with you.\n\n");
	
	//INIT STRUCTS
	cicada_window = calloc(cicada_window_max,sizeof(struct cicada_window_struct));
	cicada_sprite = calloc(cicada_sprite_max,sizeof(struct cicada_sprite_struct));
	cicada_key = calloc(cicada_key_max,sizeof(struct cicada_key_struct));
	cicada_setting = calloc(cicada_setting_max,sizeof(struct cicada_setting_struct));

	//INIT SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	Mix_Init(MIX_INIT_OGG|MIX_INIT_MP3);

	//OPEN MAIN WINDOW
	window_open("main","GAME");
}

void step(){
	//PULL INPUTS
	while(SDL_PollEvent(&cicada_event)){
		switch(cicada_event.type){
			case SDL_QUIT:
				cicada_quit();
				break;
			case SDL_WINDOWEVENT_CLOSE:
				cicada_quit();
				break;
			case SDL_KEYDOWN:
				printf("KEYCODE: %i\n",cicada_event.key.keysym.sym);
				break;
		}
	}
	//RENDER PRESENT
	for(int i = 0; i < cicada_window_max; i++){
		if(cicada_window[i].open == 1){
			SDL_RenderPresent(cicada_window[i].renderer);
		}
	}
};

void end(){
	//CLOSE UP DATA
	window_close_all();
	sprite_close_all_important();

	//FREE STRUCTS
	free(cicada_window);
	free(cicada_sprite);
	free(cicada_key);
	free(cicada_setting);

	//QUIT SDL
	SDL_Quit();
	IMG_Quit();
	Mix_Quit();
	TTF_Quit();

	//SHUT THE FUCK UP
	printf("CICADA ENDED <3!\n");
}

void cicada_quit(){
	cicada_engine.quit = 1;
}
int is_cicada_quit(){
	return cicada_engine.quit;
}

/*----------------------------------------------------------------------------------------------------
|
|	WINDOW
|
----------------------------------------------------------------------------------------------------*/
void window_open(char *id[10], char *title[50]){
	for(int i = 0; i < cicada_window_max; i++){
		if(cicada_window[i].open == 0){
			printf("WINDOW %i FOUND\n",i);
			cicada_window[i].open = 1;
			strcpy(cicada_window[i].id,id);
			strcpy(cicada_window[i].title,title);
			SDL_CreateWindowAndRenderer(640,480,SDL_WINDOW_RESIZABLE,&cicada_window[i].window,&cicada_window[i].renderer);
			SDL_SetWindowTitle(cicada_window[i].window,title);
			break;
		}
	}
}
void window_close(char *id[10]){
	for(int i = 0; i < cicada_window_max; i++){
		if(strcmp(cicada_window[i].id,id) == 0){
			SDL_DestroyWindow(cicada_window[i].window);
			SDL_DestroyRenderer(cicada_window[i].renderer);
			cicada_window[i].open = 0;
		}
	}
}

void window_close_all(){
	for(int i = 0; i < cicada_window_max; i++){
		SDL_DestroyWindow(cicada_window[i].window);
		SDL_DestroyRenderer(cicada_window[i].renderer);
		cicada_window[i].open = 0;
	}
}

void window_set_title(char *id[10], char *title[50]){
	for(int i = 0; i < cicada_window_max; i++){
		if(strcmp(cicada_window[i].id,id) == 0){
			SDL_SetWindowTitle(cicada_window[i].window,title);
		}
	}
}
void window_set_title_all(char *title[50]){
	for(int i = 0; i < cicada_window_max; i++){
		SDL_SetWindowTitle(cicada_window[i].window,title);
	}
}
void window_set_target(char *id[10]){
	for(int i = 0; i < cicada_window_max; i++){
		if(strcmp(cicada_window[i].id,id) == 0){
			cicada_engine.render_target = i;
			cicada_engine.render_target_is_texture = 0;
		}
	}
}
SDL_Renderer *window_get_renderer(){
	return cicada_window[cicada_engine.render_target].renderer;
}

void window_clear_all(){
	for(int i = 0; i < cicada_window_max; i++){
		if(cicada_window[i].open == 1){
			SDL_RenderClear(cicada_window[i].renderer);
		}
	}
}

/*----------------------------------------------------------------------------------------------------
|
|	KEY
|
----------------------------------------------------------------------------------------------------*/
void key_press(int keysym){}
void key_release(int keysym){}
void key_check(int keysym){}
void key_check_pressed(int keysym){}
void key_check_released(int keysym){}
void key_check_pressing(int keysym){}
void key_clear(){}
/*----------------------------------------------------------------------------------------------------
|
|	gamepad
|
----------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------
|
|	controller
|
----------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------
|
|	MATH
|
----------------------------------------------------------------------------------------------------*/
/*
int random(int max){
	return rand()%max+1;
}
int random_range(int min, int max){
	return (rand() %(max - min + 1)) + min;
}
float frandom(float max){
	//return (float)random()%max+1;
}
float frandom_range(float min, float max){
	//return ((float)random() %(max - min + 1)) + min;
}
*/

/*----------------------------------------------------------------------------------------------------
|
|	IMAGE LOADING
|
----------------------------------------------------------------------------------------------------*/
int sprite_load(char *name[30]){
	if(sprite_get_id(name) == -1){
		for(int i = 0; i < cicada_sprite_max; i++){
			//FIND UNLOADED SLOT
			if(cicada_sprite[i].loaded == 0){
				//GENERATE FILENAME
				char filename[100] = "assets/";
				strcat(filename,name);
				strcat(filename,".png");
				printf("filename: %s\n",filename);
				//LOAD SPRITE
				cicada_sprite[i].texture = SDL_CreateTextureFromSurface(window_get_renderer(),IMG_Load(filename));
				if(cicada_sprite[i].texture == NULL){
					printf("SPRITE LOADIN DONE GONE GOT FUCKED UP\n");
					//RETURN -1 IF CANNOT LOAD
					return -1;
				}else{
					//GET SPRITE HEIGHT AND WIDTH
					SDL_QueryTexture(cicada_sprite[i].texture,NULL,NULL,&cicada_sprite[i].w,&cicada_sprite[i].h);
					//SET COUNT
					if(cicada_sprite_count < i){
						cicada_sprite_count = i;
					}
					//FLAG SLOT AS LOADED
					cicada_sprite[i].loaded = 1;
					//SET NAME
					strcpy(cicada_sprite[i].name,name);
					//DEBUG PRINT
					printf("sprite %i loaded\n",i);
					return i;
				}
				//RETURN -1 IF CANNOT LOAD
				return -1;
			}
		}
		//RETURN -2 IF CANT FIND EMPTY SLOT
		return -2;
	}else{
		//IF SPRITES ALREADY LOADED RETURN ITS ID
		return sprite_get_id(name);
	}
}

int sprite_load_important(char *name[30]){
	cicada_sprite[sprite_load(name)].important = 1;
}

int sprite_get_id(char *name[30]){
	for(int i = 0; i <= cicada_sprite_count; i++){
		if(strcmp(cicada_sprite[i].name,name) == 0 && cicada_sprite[i].loaded == 1){
			return i;
		}
	}
	return -1;
}

void sprite_close(char *name[30]){
	for(int i = 0; i <= cicada_sprite_max; i++){
		if(strcmp(cicada_sprite[i].name,name) == 0){
			cicada_sprite[i].loaded = 0;
			cicada_sprite[i].important = 0;
			if(cicada_sprite[i].texture != NULL){
				SDL_DestroyTexture(cicada_sprite[i].texture);
			}
		}
	}
}

void sprite_close_all(){
	for(int i = 0; i <= cicada_sprite_max; i++){
		if(cicada_sprite[i].important == 0){
			cicada_sprite[i].loaded = 0;
			cicada_sprite[i].important = 0;
			if(cicada_sprite[i].texture != NULL){
				SDL_DestroyTexture(cicada_sprite[i].texture);
			}
		}
	}
}

void sprite_close_all_important(){
	for(int i = 0; i <= cicada_sprite_max; i++){
		cicada_sprite[i].loaded = 0;
		cicada_sprite[i].important = 0;
		if(cicada_sprite[i].texture != NULL){
			SDL_DestroyTexture(cicada_sprite[i].texture);
		}
	}
}

/*----------------------------------------------------------------------------------------------------
|
|	SPRITE DRAWING
|
----------------------------------------------------------------------------------------------------*/
void draw_sprite_hud(char *name[30], int x, int y, int sx, int sy, int w, int h){
	int sprite_id = sprite_load(name);
	if(w > cicada_sprite[sprite_id].w){w = cicada_sprite[sprite_id].w;}
	if(h > cicada_sprite[sprite_id].h){h = cicada_sprite[sprite_id].h;}
	SDL_Rect srcrect;
	srcrect.x = sx;
	srcrect.y = sy;
	srcrect.w = w;
	srcrect.h = h;
	SDL_Rect dstrect;
	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = w;
	dstrect.h = h;
	SDL_RenderCopy(window_get_renderer(),cicada_sprite[sprite_id].texture,&srcrect,&dstrect);
};

void draw_sprite_hud_ex(){};
void draw_sprite(){};
void draw_sprite_ex(){};