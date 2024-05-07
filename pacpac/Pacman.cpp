#include "Pacman.h"

Pacman::Pacman()
{
	//load pac texture
	if (!pacman_texture.loadFromFile("Visuals\\pacman_otwarty_2.png"))
	{
		std::cerr << "Failed to load pac" << std::endl;
	}
	else
	{
		this->pacman_sprite.setTexture(pacman_texture);
	}

	//set origin and starting position of pacman
	pacBounds = pacman_sprite.getLocalBounds();
	pacman_sprite.setOrigin(pacBounds.width / 2.0f, pacBounds.height / 2.0f);

	pacman_sprite.setPosition(xpos, ypos);

	eat_counter = 1;
	eating = false;
}

//TUUUUUUU
void Pacman::move(const Direction& dirr)
{
	if (eating)
	{
		eat_counter++;
		eat(eat_counter);
	}	

	changepos(dirr);
	switch (dir)
	{
	case Direction::LEFT:
		pacman_sprite.setRotation(0.f);
		pacman_sprite.scale(1, 1);
	break;
	case Direction::RIGHT:
		pacman_sprite.setRotation(180.f);
	break;
	case Direction::UP:
		pacman_sprite.setRotation(90.f);
	break;
	case Direction::DOWN:
		pacman_sprite.setRotation(-90.f);
	break;
	default:
	break;
	}
	pacman_sprite.setPosition(xpos, ypos);

	return;
}

void Pacman::eat(const int& state)
{
	if (state == 1 || state == 2 )
	{
		eating = true;
		pacman_texture.loadFromFile("Visuals\\pacman_changing_1.png");
	}
	else if (state == 3 || state == 4 )
	{
		pacman_texture.loadFromFile("Visuals\\pacman_changing_2.png");
	}
	else if (state == 5 || state == 6 )
	{
		pacman_texture.loadFromFile("Visuals\\pacman_changing_3.png");
	}
	else if (state == 7 || state == 8 )
	{
		pacman_texture.loadFromFile("Visuals\\pacman_zamkniety_2.png");
	}
	else if (state == 9 || state == 10 )
	{
		pacman_texture.loadFromFile("Visuals\\pacman_changing_3.png");
	}
	else if (state == 11 || state == 12)
	{
		pacman_texture.loadFromFile("Visuals\\pacman_changing_2.png");
	}
	else if (state == 13 || state == 14)
	{
		pacman_texture.loadFromFile("Visuals\\pacman_changing_1.png");
	}
	else if (state == 15)
	{
		pacman_texture.loadFromFile("Visuals\\pacman_otwarty_2.png");
		eating = false;
		eat_counter = 1;
	}

	pacBounds = pacman_sprite.getLocalBounds();
	pacman_sprite.setOrigin(pacBounds.width / 2.0f, pacBounds.height / 2.0f);

	pacman_sprite.setPosition(xpos, ypos);
			
}

void Pacman::draw(sf::RenderTarget* window)
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







