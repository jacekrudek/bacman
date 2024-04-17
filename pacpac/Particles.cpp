#include "Particles.h"

Particles::Particles()
{
	active = {
		{40, {525}},
		{80, {210, 260, 310, 342.5, 375, 525, 675, 712.5, 750, 825, 862.5, 900}},
		{130, {210,310,375,525,675,750,787.5,825,900}},
		{170, {210,310,375,525,675,825,900}},
		{210, {210,260,310,342.5,375,412.5,450,487.5,525,562.5,600,637.5,675,712.5,750,787.5,825,900}},
		{247.5, {210,310,525,675,750,900}},
		{285, {210,310,342.5,375,450,487.5,525,562.5,600,637.5,675,750,787.5,825,900}},
		{322.5, {210,310,375,450,600,675,750,825,900}},
		{360, {210,260,310,375,412.5,450,600,675,712.5,750,825,862.5,900}},
		{400, {310,450,600,750,900}},
		{440, {210,260,310,375,412.5,450,600,675,712.5,750,825,862.5,900}},
		{477.5, {210,310,375,450,600,675,750,825,900}},
		{515, {210,310,342.5,375,450,487.5,525,562.5,600,637.5,675,750,787.5,825,900}},
		{552.5, {210,310,525,675,750,900}},
		{590, {210,260,310,342.5,375,412.5,450,487.5,525,562.5,600,637.5,675,712.5,750,787.5,825,900}},
		{630, {210,310,375,525,675,825,900}},
		{670, {210,310,375,525,675,750,787.5,825,900}},
		{720, {210,260,310,342.5,375,525,675,712.5,750,825,862.5,900}},
		{760, {525}}
	};

	//load particle sprite
	if (!part_texture.loadFromFile("particle.png"))
	{
		std::cerr << "Failed to load map" << std::endl;
	}
	else
	{
		this->part_sprite.setTexture(part_texture);
	}

	//set origin of particle sprite
	part_sprite.setOrigin(part_texture.getSize().x / 2.0f, part_texture.getSize().y / 2.0f);

	for (const auto& x : active)
	{
		for (const auto& y : x.second)
		{
			particle_sprites.push_back(part_sprite);
		}
	}

	initparticles();
}

void Particles::initparticles()
{
	std::vector<sf::Sprite>::iterator it = particle_sprites.begin();

	for (const auto& x : active)
	{
		for (const auto& y : x.second)
		{
			if (it != particle_sprites.end())
			{
				it->setPosition(x.first, y);
				++it;
			}
		}
	}

	return;
}

void Particles::updateparticles(Pacman& pacman)
{
	float pacposx = pacman.getposx();
	float pacposy = pacman.getposy();
	sf::Vector2f position;

	for (int i = 0; i < particle_sprites.size(); i++)
	{
		position = particle_sprites[i].getPosition();
		if (position.x < pacposx + 17 && position.x > pacposx - 17
			&& position.y < pacposy + 17 && position.y > pacposy - 17)
		{
			particle_sprites.erase(particle_sprites.begin() + i);
			pacman.eat(1);
		}
	}

}

bool Particles::eaten()
{
	if (particle_sprites.empty())
	{
		return true;
	}
	return false;
}


void Particles::draw(sf::RenderTarget* window)
{
	for (const auto& sprite : particle_sprites)
	{
		window->draw(sprite);
	}
}

Particles::~Particles()
{

}






