#pragma once
#ifndef MAP_H
#define MAP_H

#include "libraries.h"

#include "Position.h"
#include "Pacman.h"



class Map
{
	sf::Texture map_texture;
	sf::Sprite map_sprite;

	sf::Texture texture;
	sf::Sprite sprite;

public:
	Map();
	~Map();

	void draw(sf::RenderWindow* window);

	//void initborders();

	//void testborders();
};

#endif // !MAP_H


