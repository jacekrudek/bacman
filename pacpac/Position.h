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
protected:
	Direction dir;
	float xpos;
	float ypos;

public:
	Position();
	~Position() {};

	void changepos(const Direction& dirr);

};

#endif // !Position_H


