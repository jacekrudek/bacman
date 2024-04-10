#include "Gameplay.h"

/**
* @brief Function calling pacman-moving function in Movement class if there is any user input movement-related
*/
void Gameplay::movepac(const Direction& dirr)
{
	movement.movepac(pacman, dirr);
	particles.updateparticles(pacman);
}

/**
* @brief Function calling pacman-moving function in Movement class if there is no user input movement-related
*/
void Gameplay::movepac()
{
	movement.movepac(pacman, pacman.getdir());
	particles.updateparticles(pacman);
}

/**
* @brief Function managing rendering when in-game
*/
void Gameplay::draw(sf::RenderWindow* window)
{
	map.draw(window);
	//movement.draw(window);
	particles.draw(window);
	pacman.draw(window);
}




