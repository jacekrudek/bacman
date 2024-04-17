#include "Map.h"

/**
* @brief Map class default constructor loading map texture and setting correct position of it 
*/
Map::Map()
{
	//load map
	if (!map_texture.loadFromFile("puremap2.png"))
	{
		std::cerr << "Failed to load map" << std::endl;
	}
	else
	{
		this->map_sprite.setTexture(map_texture);
	}

	//set position of map
	map_sprite.setOrigin(map_texture.getSize().x / 2.0f, map_texture.getSize().y / 2.0f);

	map_sprite.setPosition(400, 500);
	
}

/**
* @brief Map draw function
*/
void Map::draw(sf::RenderTarget* window)
{
	window->draw(map_sprite);
}

/**
* @brief Map class default destructor
*/
Map::~Map()
{

}

