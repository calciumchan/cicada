//this is a base entity
//all other entities should inherit from this entity

#pragma once
#include "meta.h"

class ce_entity{
	public:
	void start();
	void end();
	void step();
	void draw();
	private:
	int x,y;
}
