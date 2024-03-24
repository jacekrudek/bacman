#include "Map.h"

Map::Map()
{
	//load map
	if (!map_texture.loadFromFile("puremap.png"))
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

	//initialize borders
	initborders();	

	//testborders();
}

void Map::draw(sf::RenderWindow* window)
{
	window->draw(map_sprite);
	//window->draw(sprite);
	pacman.draw(window);
}

void Map::initborders()
{
	//initialize border values
	borders.insert({
		//top border
		{Border::TOP, {
			{186, { {54, 392}, {417, 755}}},
			{280, { {104, 184}, {238, 341}, {392, 418}, {471, 575}, {628, 708}}},
			{353, { {104, 184}, {318, 392}, {417, 496}, {628, 708}}},
			{430, { {260, 341}, {392, 417}, {470, 550}}},
			{502, { {0, 185}, {237, 261}, {550, 574}, {624, 800}}},
			{576, { {317, 496}}},
			{648, { {54, 185}, {237, 260}, {318, 393}, {417, 495}, {550, 574}, {624, 756}}},
			{723, { {106, 161}, {238, 341}, {392, 417}, {470, 573}, {651, 706}}},
			{797, { {54, 102}, {161, 185}, {318, 392}, {417, 496}, {628, 651}, {708, 755}}},
			{871, { {104, 339}, {392, 417}, {471, 706}}}
		}},
		//bot border
		{Border::BOT, {
			{234, { {104, 183}, {237, 341}, {471, 574}, {628, 708}}},
			{331, { {104, 183}, {237, 260}, {318, 496}, {551, 574}, {628, 708}}},
			{401, { {54, 186}, {260, 341}, {470, 551}, {624, 755}}},
			{479, { {317, 495}}},
			{548, { {0, 186}, {237, 260}, {550, 573}, {624, 800}}},
			{627, { {318, 496}}},
			{700, { {106, 184}, {239, 341}, {470, 574}, {628, 706}}},
			{774, { {54, 101}, {236, 260}, {318, 496}, {550, 574}, {709, 756}}},
			{850, { {104, 236}, {260, 339}, {471, 550}, {574, 706}}},
			{916, { {54, 756}}}
		}},
		//right border
		{Border::RIGHT, {
			{105, { {235, 279}, {331, 353}, {700, 723}, {850, 871}}},
			{162, { {723, 797}}},
			{238, { {234, 280}, {332, 501}, {553, 649}, {700, 722}, {774, 851}}},
			{318, { {331, 353}, {479, 576}, {627, 648}, {774, 795}}},
			{392, { {186, 282}, {353, 429}, {649, 724}, {795, 871}}},
			{472, { {234, 280}, {406, 430}, {701, 723}, {850, 871}}},
			{551, { {331, 407}, {430, 501}, {553, 649}, {774, 850}}},
			{628, { {234, 279}, {331, 353}, {401, 502}, {548, 649}, {700, 797}}},
			{709, { {774, 797}}},
			{755, { {186, 401}, {650, 774}, {797, 916}}}
		}},
		//left border
		{Border::LEFT, {
			{54, { {186, 402}, {649, 774}, {797, 916}}},
			{101, { {774, 797}}},
			{185, { {234, 280}, {331, 353}, {401, 502}, {548, 649}, {701, 797}}},
			{260, { {331, 407}, {430, 501}, {552, 649}, {775, 850}}},
			{341, { {234, 280}, {407, 429}, {700, 723}, {850, 871}}},
			{417, { {186, 282}, {353, 429}, {648, 723}, {796, 871}}},
			{496, { {332, 352}, {479, 577}, {626, 648}, {774, 795}}},
			{575, { {234, 280}, {332, 501}, {553, 649}, {700, 723}, {774, 850}}},
			{651, { {723, 797}}},
			{708, { {234, 280}, {331, 352}, {700, 723}, {850, 871}}}
		}}
		});
		

	return;
}



bool Map::canmove(const Direction& dirr)
{
	bool pathopen = true;
	bool found = false;

	if (dirr == Direction::LEFT)
	{
		for (const auto& bordermap : borders)
		{
			if (bordermap.first == Border::LEFT)
			{
				for (const auto& key : bordermap.second)
				{
					float temp = pacman.getposx() - key.first;
					if (temp < 30 && temp > 0)
					{
						for (const auto& length : key.second)
						{							
							if (pacman.getposy() > length.first && pacman.getposy() < length.second)
							{
								pathopen = false;
								found = true;
							}							
						}
					}					
				}
			}
		}
	}
	else if (dirr == Direction::RIGHT)
	{
		for (const auto& bordermap : borders)
		{
			if (bordermap.first == Border::RIGHT)
			{
				for (const auto& key : bordermap.second)
				{
					float temp = key.first - pacman.getposx();
					if (temp < 30 && temp > 0)
					{
						for (const auto& length : key.second)
						{
							if (pacman.getposy() > length.first && pacman.getposy() < length.second)
							{
								pathopen = false;
								found = true;
							}
						}
					}
				}
			}
		}
	}
	else if (dirr == Direction::UP)
	{
		for (const auto& bordermap : borders)
		{
			if (bordermap.first == Border::TOP)
			{
				for (const auto& key : bordermap.second)
				{
					float temp = pacman.getposy() - key.first;
					if (temp < 30 && temp > 0)
					{
						for (const auto& length : key.second)
						{
							if (pacman.getposx() > length.first && pacman.getposx() < length.second)
							{
								pathopen = false;
								found = true;
							}
						}
					}
				}
			}
		}
	}
	else if (dirr == Direction::DOWN)
	{
		for (const auto& bordermap : borders)
		{
			if (bordermap.first == Border::BOT)
			{
				for (const auto& key : bordermap.second)
				{
					float temp = key.first - pacman.getposy();
					if (temp < 30 && temp > 0)
					{
						for (const auto& length : key.second)
						{
							if (pacman.getposx() > length.first && pacman.getposx() < length.second)
							{
								pathopen = false;
								found = true;
							}
						}
					}
				}
			}
		}
	}

	switch (pathopen)
	{
	case true:
		std::cout << "path open" << std::endl;
		break;
	case false:
		std::cout << "path closed" << std::endl;
		break;
	}

	return pathopen;
}

void Map::setcorrpos(const Direction& dirr, bool& isok)
{
	int min_cord = std::numeric_limits<int>::max();
	int max_cord = 0;

	int min = std::numeric_limits<int>::max();
	int max = std::numeric_limits<int>::max();

	if (dirr == Direction::LEFT)
	{
		for (const auto& bordermap : borders)
		{
			if (bordermap.first == Border::TOP)
			{
				for (const auto& key : bordermap.second)
				{
					float temp = pacman.getposy() - key.first;
					if (temp < 40 && temp > 0)
					{
						min_cord = key.first;
					}
				}
			}
			else if (bordermap.first == Border::BOT)
			{
				for (const auto& key : bordermap.second)
				{
					float temp = key.first - pacman.getposy();
					if (temp < 40 && temp > 0)
					{
						max_cord = key.first;
					}
				}
			}
		}
		if (min_cord != std::numeric_limits<int>::max() && max_cord != 0)
		{
			float temp = (min_cord + max_cord) / 2;
			pacman.setposy(temp);
			isok = true;
		}
	}
	else if (dirr == Direction::RIGHT)
	{
		for (const auto& bordermap : borders)
		{
			if (bordermap.first == Border::TOP)
			{
				for (const auto& key : bordermap.second)
				{
					float temp = pacman.getposy() - key.first;
					if (temp < 40 && temp > 0)
					{
						min_cord = key.first;
					}
				}
			}
			else if (bordermap.first == Border::BOT)
			{
				for (const auto& key : bordermap.second)
				{
					float temp = key.first - pacman.getposy();
					if (temp < 40 && temp > 0)
					{
						max_cord = key.first;
					}
				}
			}
		}
		if (min_cord != std::numeric_limits<int>::max() && max_cord != 0)
		{
			float temp = (min_cord + max_cord) / 2;
			pacman.setposy(temp);
			isok = true;
		}
	}
	else if (dirr == Direction::UP)
	{
		for (const auto& bordermap : borders)
		{
			if (bordermap.first == Border::RIGHT)
			{
				for (const auto& key : bordermap.second)
				{
					float temp = key.first - pacman.getposx();
					if (temp < 40 && temp > 0)
					{
						min_cord = key.first;
					}
				}
			}
			else if (bordermap.first == Border::LEFT)
			{
				for (const auto& key : bordermap.second)
				{
					float temp = pacman.getposx() - key.first;
					if (temp < 40 && temp > 0)
					{
						max_cord = key.first;
					}
				}
			}
		}
		if (min_cord != std::numeric_limits<int>::max() && max_cord != 0)
		{
			float temp = (min_cord + max_cord) / 2;
			pacman.setposx(temp);
			isok = true;
		}
	}
	else if (dirr == Direction::DOWN)
	{
		for (const auto& bordermap : borders)
		{
			if (bordermap.first == Border::RIGHT)
			{
				for (const auto& key : bordermap.second)
				{
					float temp = key.first - pacman.getposx() ;
					if (temp < 40 && temp > 0)
					{
						min_cord = key.first;
					}
				}
			}
			else if (bordermap.first == Border::LEFT)
			{
				for (const auto& key : bordermap.second)
				{
					float temp = pacman.getposx() - key.first;
					if (temp < 40 && temp > 0)
					{
						max_cord = key.first;
					}
				}
			}
		}
		if (min_cord != std::numeric_limits<int>::max() && max_cord != 0)
		{
			float temp = (min_cord + max_cord) / 2;
			pacman.setposx(temp);
			isok = true;
		}
	}

	return;
}

void Map::testborders()
{
	sf::Image image;
	image.create(800, 1000, sf::Color::Transparent);

	for (const auto& bordermap : borders)
	{
		if (bordermap.first == Border::LEFT || bordermap.first == Border::RIGHT)
		{
			for (const auto& key : bordermap.second)
			{
				for (const auto& length : key.second)
				{
					for (int i = length.first; i < length.second; i++)
					{
						image.setPixel(key.first,i,sf::Color::Blue);
					}
				}
			}
		}
		else
		{
			for (const auto& key : bordermap.second)
			{
				for (const auto& length : key.second)
				{
					for (int i = length.first; i < length.second; i++)
					{
						image.setPixel(i, key.first, sf::Color::Blue);
					}
				}
			}
		}
	}

	texture.loadFromImage(image);
	sprite.setTexture(texture);

	return;
}



void Map::movepac(const Direction& dirr)
{		
	if (canmove(dirr) == true)
	{
		if ((pacman.getdir() == Direction::LEFT && (dirr == Direction::LEFT || dirr == Direction::RIGHT)) ||
			(pacman.getdir() == Direction::RIGHT && (dirr == Direction::LEFT || dirr == Direction::RIGHT)) ||
			(pacman.getdir() == Direction::UP && (dirr == Direction::UP || dirr == Direction::DOWN)) ||
			(pacman.getdir() == Direction::DOWN && (dirr == Direction::UP || dirr == Direction::DOWN)))
		{
			pacman.move(dirr);
		}
		else
		{
			bool isok = false;
			setcorrpos(dirr, isok);
			if (isok == true)
			{
				pacman.move(dirr);
			}
		}
	}

	return;
}

Direction Map::getdir()
{
	return pacman.getdir();
}

Map::~Map()
{

}

