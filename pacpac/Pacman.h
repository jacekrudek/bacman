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

	sf::FloatRect pacBounds;

	//for animation
	int eat_counter;
	bool eating;
public:
	Pacman();
	~Pacman();

	void move(const Direction& dirr);

	void draw(sf::RenderTarget* window);

	Direction getdir();
	float getposx();
	float getposy();

	void eat(const int& state);

	void setposx(const float& x);
	void setposy(const float& y);
};

#endif // !PACMAN_H


