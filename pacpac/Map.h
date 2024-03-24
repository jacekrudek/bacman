#pragma once
#ifndef MAP_H
#define MAP_H

#include "libraries.h"

#include "Position.h"
#include "Pacman.h"

enum class Border {
	TOP,
	BOT,
	LEFT,
	RIGHT
};

class Map
{
	sf::Texture map_texture;
	sf::Sprite map_sprite;

	std::map<Border, std::map<int, std::vector<std::pair<int, int>>>> borders;

	Pacman pacman;

	sf::Texture texture;
	sf::Sprite sprite;

public:
	Map();
	~Map();

	void draw(sf::RenderWindow* window);

	void initborders();

	bool canmove(const Direction& dirr);

	void testborders();

	void movepac(const Direction& dirr);

	Direction getdir();

	void setcorrpos(const Direction& dirr, bool& isok);
};

#endif // !MAP_H


