#include "Position.h"


Position::Position()
{
	dir = Direction::LEFT;
	xpos = 407;
	ypos = 746;
}

void Position::move(const Direction& dirr)
{
	switch (dirr)
	{
	case Direction::LEFT:
		xpos--;
		dir = Direction::LEFT;
		break;
	case Direction::RIGHT:
		xpos++;
		dir = Direction::RIGHT;
		break;
	case Direction::UP:
		ypos--;
		dir = Direction::UP;
		break;
	case Direction::DOWN:
		ypos++;
		dir = Direction::DOWN;
		break;
	default:
		break;
	}

	return;
}

float Position::getx()
{
	return xpos;
}

float Position::gety()
{
	return ypos;
}




