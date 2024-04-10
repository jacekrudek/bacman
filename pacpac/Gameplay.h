#pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "libraries.h"

#include "Map.h"
#include "Pacman.h"
#include "Movement.h"
#include "Particles.h"

/**
* @brief Main class for managing gameplay
* 
* @param Map class including map image
* @param Pacman class including pacman image and pacman-related variables
* @param Movement class that manages pacman and ghosts movement
* 
*/

class Gameplay
{
	Map map;
	Pacman pacman;
	Movement movement;
	Particles particles;

public:

	void movepac(const Direction& dirr);
	void movepac();

	void draw(sf::RenderWindow* window);
};

#endif

