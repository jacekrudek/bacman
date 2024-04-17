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

	//vertexes x and y coords
	std::vector<std::pair<float, float>> vertexes;

	//from, to, distance
	std::map<int, std::map<int, int>> distances;
	
	std::vector<std::pair<bool, int >> dijkstra_path;
	
	std::vector<std::pair<float, float>> ghost1vertexes;
	std::vector<std::pair<float, float>> ghost2vertexes;
	std::vector<std::pair<float, float>> ghost3vertexes;
	std::vector<std::pair<float, float>> ghost4vertexes;


	Dir_buffer dir_buffer;

public:
	sf::Texture texture;
	sf::Sprite sprite;

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

	void testborders();

	void draw(sf::RenderWindow* window);
};

#endif // !MOVEMENT_H
