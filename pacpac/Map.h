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

	Position pacposition;
	Pacman pacman;

public:
	Map();
	~Map();

	void draw(sf::RenderWindow* window);

	void initborders();

	bool canmove(const Direction& dirr);
};

#endif // !MAP_H


