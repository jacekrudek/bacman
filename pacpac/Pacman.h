#pragma once
#ifndef PACMAN_H
#define PACMAN_H

#include "libraries.h"

#include "Position.h"

class Pacman
	:public Position
{
	sf::Texture pacman_texture;
	sf::Sprite pacman_sprite;

public:
	Pacman();
	~Pacman();

	void move(const Direction& dirr);

	void draw(sf::RenderWindow* window);

	Direction getdir();
	float getposx();
	float getposy();

	void setposx(const float& x);
	void setposy(const float& y);
};

#endif // !PACMAN_H


