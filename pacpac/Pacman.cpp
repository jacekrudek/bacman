#include "Pacman.h"

Pacman::Pacman()
{
	//load pac texture
	if (!pacman_texture.loadFromFile("pacman.png"))
	{
		std::cerr << "Failed to load map" << std::endl;
	}
	else
	{
		this->pacman_sprite.setTexture(pacman_texture);
	}

	//set origin and starting position of pacman
	sf::FloatRect pacBounds = pacman_sprite.getLocalBounds();
	pacman_sprite.setOrigin(pacBounds.width / 2.0f, pacBounds.height / 2.0f);

	pacman_sprite.setPosition(position.getx(), position.gety());
}

void Pacman::move(const Direction& dirr)
{
	position.move(dirr);

	return;
}

void Pacman::draw(sf::RenderWindow* window)
{
	window->draw(pacman_sprite);

	return;
}

float Pacman::getposx()
{
	return position.getx();
}

float Pacman::getposy()
{
	return position.gety();
}

Pacman::~Pacman()
{

}





