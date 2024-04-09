#include "Gameplay.h"


void Gameplay::movepac(const Direction& dirr)
{
	movement.movepac(pacman, dirr);
}

void Gameplay::movepac()
{
	movement.movepac(pacman, pacman.getdir());
}

void Gameplay::draw(sf::RenderWindow* window)
{
	//map.draw(window);
	pacman.draw(window);
	movement.draw(window);
}




