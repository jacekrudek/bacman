#pragma once
#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "libraries.h"

#include "Position.h"
#include "Pacman.h"
#include "Ghost.h"

enum class Border {
	TOP,
	BOT,
	LEFT,
	RIGHT
};

struct Dir_buffer {
	bool active;
	float cord;
	Direction dir;
};

class Movement
{
	std::map<Border, std::map<int, std::vector<std::pair<int, int>>>> borders;
	
	std::vector<std::pair<float, float>> ghost1vertexes;
	std::vector<std::pair<float, float>> ghost2vertexes;
	std::vector<std::pair<float, float>> ghost3vertexes;
	std::vector<std::pair<float, float>> ghost4vertexes;

	Dir_buffer dir_buffer;

	sf::Texture texture;
	sf::Sprite sprite;
public:

	Movement();

	void initborders();
	void initvertexes();
	bool canmove(Pacman& pacman, const Direction& dirr);
	bool checkcorrpos(Pacman& pacman);
	void movepac(Pacman& pacman, const Direction& dirr);
	void moveghost(Ghost& ghost);
	void findcorrpos(Pacman& pacman, const Direction& dirr, float& min, float& max);
	bool sameaxis(Pacman& pacman, const Direction& dirr);
	bool colision(Pacman& pacman, Ghost& ghost);

	void draw(sf::RenderWindow* window);
};

#endif // !MOVEMENT_H
