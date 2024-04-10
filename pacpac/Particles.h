#pragma once
#ifndef PARTICLES_H
#define PARTICLES_H


#include "libraries.h"
#include "Pacman.h"

class Particles
{
	std::map<float, std::vector<float>> active;

	sf::Texture part_texture;
	sf::Sprite part_sprite;

	std::vector<sf::Sprite> particle_sprites;
public:
	Particles();
	~Particles();

	void initparticles();

	void updateparticles(Pacman& pacman);

	void draw(sf::RenderWindow* window);
};

#endif // !"PARTICLES_H"

