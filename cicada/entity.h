//this is a base entity
//all other entities should inherit from this entity

#pragma once
#include "meta.h"

class ce_entity{
	public:
	ce_entity();
	
	//creat and destroy
	void start();
	void end();

	//step events
	void step_start();
	void step();
	void step_end();
	
	//draw events
	void draw_start();
	void draw();
	void draw_end();
	private:

	//is this even a good idea?
	int x,y;
};
