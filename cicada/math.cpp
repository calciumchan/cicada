#include "math.h"

void randomize(){
	srand(1000);
}

void randomize_seed(float seed){
	srand(seed);
}

int random(int max){
	return rand()%max;
}
int random_range(int min, int max){
	return min+(rand()%(max-min));
}
/* gotta come back to this later
float frandom(float max){
	return rand()%max;
}
float frandom_range(float min, float max){
	return min+(rand()%(max-min));
}
*/
int min(int a, int b){
	if( a > b){
		return b;
	}else{
		return a;
	}
}

int max(int a, int b){
	if( a < b){
		return b;
	}else{
		return a;
	}
}
