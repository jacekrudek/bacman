#pragma once
#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "libraries.h"

#include "Position.h"
#include "Pacman.h"

enum class Border {
	TOP,
	BOT,
	LEFT,
	RIGHT
};

struct Dir_buffer {
	bool active;
	float cord;
	Direction dir;
};

class Movement
{
	std::map<Border, std::map<int, std::vector<std::pair<int, int>>>> borders;

	Dir_buffer dir_buffer;

public:
	Movement();

	void initborders();
	bool canmove(Pacman& pacman, const Direction& dirr);
	void setcorrpos(Pacman& pacman, const Direction& dirr, bool& isok);
	void movepac(Pacman& pacman, const Direction& dirr);
	//void checkpos();
};

#endif // !MOVEMENT_H
