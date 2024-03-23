#pragma once
#ifndef Position_H
#define Position_H

#include "libraries.h"


enum class Direction {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Position
{
	Direction dir;
	float xpos;
	float ypos;

public:
	Position();
	~Position() {};

	void move(const Direction& dirr);

	float getx();
	float gety();
};

#endif // !Position_H


