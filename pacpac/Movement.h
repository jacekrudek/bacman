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
	sf::Texture texture;
	sf::Sprite sprite;

	Movement();

	void initborders();
	bool canmove(Pacman& pacman, const Direction& dirr);
	bool checkcorrpos(Pacman& pacman);
	void movepac(Pacman& pacman, const Direction& dirr);
	//void setbuffer(const bool& canmove, Dir_buffer& dir_buffer);
	//void checkpos();

	void testborders();

	void draw(sf::RenderWindow* window);
};

#endif // !MOVEMENT_H
