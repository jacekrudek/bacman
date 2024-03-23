#pragma once
#ifndef PACMAN_H
#define PACMAN_H

#include "libraries.h"

#include "Position.h"

class Pacman
{
	sf::Texture pacman_texture;
	sf::Sprite pacman_sprite;

	Position position;

public:
	Pacman();
	~Pacman();

	void move(const Direction& dirr);

	void draw(sf::RenderWindow* window);

	float getposx();
	float getposy();
};

#endif // !PACMAN_H


