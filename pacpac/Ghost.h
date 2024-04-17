#pragma once
#ifndef Ghost_H
#define Ghost_H

#include "libraries.h"

#include "Position.h"

class Ghost
	: public Position
{
	sf::Texture ghost_texture;
	sf::Sprite ghost_sprite;
	
	sf::FloatRect ghostBounds;

	//which of the four ghosts it is
	int ghost_index;

public:
	Ghost(const int& index);

	void move(const Direction& dirr);

	void draw(sf::RenderTarget* window);

	Direction getdir();
	float getposx();
	float getposy();

	int getindex();

	void setposx(const float& x);
	void setposy(const float& x);
	void setdir(const Direction& dirr);
};

#endif

