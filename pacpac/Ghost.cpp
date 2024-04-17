#include "Ghost.h"

Ghost::Ghost(const int& index)
{
	ghost_index = index;	

	switch (ghost_index)
	{
	case 1:
		ghost_texture.loadFromFile("ghost_red.png");
		this->ghost_sprite.setTexture(ghost_texture);
		break;
	case 2:
		ghost_texture.loadFromFile("ghost_orange.png");
		this->ghost_sprite.setTexture(ghost_texture);
		break;
	case 3:
		ghost_texture.loadFromFile("ghost_cyan.png");
		this->ghost_sprite.setTexture(ghost_texture);
		break;
	case 4:
		ghost_texture.loadFromFile("ghost_pink.png");
		this->ghost_sprite.setTexture(ghost_texture);
		break;
	}

	//set origin and starting position of pacman
	ghostBounds = ghost_sprite.getLocalBounds();
	ghost_sprite.setOrigin(ghostBounds.width / 2.0f, ghostBounds.height / 2.0f);
	
	
	switch (ghost_index)
	{
	case 1:
		xpos = 80;
		ypos = 210;
		dir = Direction::RIGHT;
		break;
	case 2:
		xpos = 440;
		ypos = 375;
		dir = Direction::UP;
		break;
	case 3:
		xpos = 360;
		ypos = 900;
		dir = Direction::UP;
		break;
	case 4:
		xpos = 590;
		ypos = 675;
		dir = Direction::RIGHT;
		break;
	default:
		break;
	}
	
	ghost_sprite.setPosition(xpos, ypos);
}

void Ghost::move(const Direction& dirr)
{
	changepos(dirr);
	ghost_sprite.setPosition(xpos, ypos);

	return;
}

void Ghost::draw(sf::RenderTarget* window)
{
	window->draw(ghost_sprite);
}
	
Direction Ghost::getdir()
{
	return dir;
}

float Ghost::getposx()
{
	return xpos;
}

float Ghost::getposy()
{
	return ypos;
}

void Ghost::setposx(const float& x)
{
	xpos = x;
	return;
}

void Ghost::setposy(const float& y)
{
	ypos = y;
	return;
}

void Ghost::setdir(const Direction& dirr)
{
	dir = dirr;
	return;
}

int Ghost::getindex()
{
	return ghost_index;
}

