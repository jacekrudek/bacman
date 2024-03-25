#pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "libraries.h"

#include "Map.h"
#include "Pacman.h"
#include "Movement.h"

class Gameplay
{
	Map map;
	Pacman pacman;
	Movement movement;

public:

	void movepac(const Direction& dirr);
	void movepac();

	void draw(sf::RenderWindow* window);
};

#endif

