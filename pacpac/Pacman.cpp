#include "Pacman.h"

Pacman::Pacman()
{
	//load pac texture
	if (!pacman_texture.loadFromFile("pacman_otwarty_2.png"))
	{
		std::cerr << "Failed to load pac" << std::endl;
	}
	else
	{
		this->pacman_sprite.setTexture(pacman_texture);
	}

	//set origin and starting position of pacman
	sf::FloatRect pacBounds = pacman_sprite.getLocalBounds();
	pacman_sprite.setOrigin(pacBounds.width / 2.0f, pacBounds.height / 2.0f);

	pacman_sprite.setPosition(xpos, ypos);
}

//TUUUUUUU
void Pacman::move(const Direction& dirr)
{
	changepos(dirr);
	pacman_sprite.setPosition(xpos, ypos);

	return;
}

void Pacman::draw(sf::RenderWindow* window)
{
	window->draw(pacman_sprite);

	return;
}

Direction Pacman::getdir()
{
	return dir;
}

float Pacman::getposx()
{
	return xpos;
}

float Pacman::getposy()
{
	return ypos;
}

void Pacman::setposx(const float& x)
{
	xpos = x;
	return;
}

void Pacman::setposy(const float& y)
{
	ypos = y;
	return;
}

Pacman::~Pacman()
{

}







