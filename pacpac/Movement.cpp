#include "Movement.h"

/**
* @brief Movement class default constructor
* 
* @details
* Initializes all border values 
* Sets default values of pacman-direction-change buffer, used to smoothen out changing directions when
* user direction-changing input is semi-perfect 
*/
Movement::Movement()
{
	initborders();

	dir_buffer.active = false;
	dir_buffer.cord = 0;
	dir_buffer.dir = Direction::LEFT;

	testborders();
}

/**
* @brief Function initializing all border values 
*/
void Movement::initborders()
{
	borders.insert({
		//top border
		{Border::TOP, {
			{185, { {55, 385}, {415, 745}}},
			{285, { {105, 185}, {235, 335},{385, 415}, {465, 565}, {615, 695}}},
			{350, { {105, 185}, {310, 385}, {415, 490}, {615, 695}}},
			{425, { {260, 335}, {385, 415}, {465, 540}}},
			{500, { {0, 185}, {235, 260}, {540, 565}, {615, 800}}},
			{575, { {310, 490}}},
			{650, { {55, 185}, {235, 260}, {310, 385}, {415, 490}, {540, 565}, {615, 745}}},
			{725, { {105, 155}, {235, 335}, {385, 415}, {465, 565}, {645, 695}}},
			{800, { {55, 105}, {155, 185}, {310, 385}, {415, 490}, {615, 645}, {695, 745}}},
			{875, { {105, 335}, {385, 415}, {465, 695}}}
		}},
		//bot border
		{Border::BOT, {
			{235, { {105, 185}, {235, 335}, {465, 565}, {615, 695}}},
			{335, { {105, 185}, {235, 260}, {310, 490}, {540, 565}, {615, 695}}},
			{400, { {55, 185}, {260, 335}, {465, 540}, {615, 745}}},
			{475, { {310, 490}}},
			{550, { {0, 185}, {235, 260}, {540, 565}, {615, 800}}},
			{625, { {310, 490}}},
			{700, { {105, 185}, {235, 335}, {465, 565}, {615, 695}}},
			{775, { {55, 105}, {235, 260}, {310, 490}, {540, 565}, {695, 745}}},
			{850, { {105, 235}, {260, 335}, {465, 540}, {565, 695}}},
			{925, { {55, 745}}}
		}},
		//right border
		{Border::RIGHT, {
			{105, { {235, 285}, {335, 350}, {700, 725}, {850, 875}}},
			{155, { {725, 800}}},
			{235, { {235, 285}, {335, 500}, {550, 650}, {700, 725}, {775, 850}}},
			{310, { {335, 350}, {475, 575}, {625, 650}, {775, 800}}},
			{385, { {185, 285}, {350, 425}, {650, 725}, {800, 875}}},
			{465, { {235, 285}, {400, 425}, {700, 725}, {850, 875}}},
			{540, { {335, 400}, {425, 500}, {550, 650}, {775, 850}}},
			{615, { {235, 285}, {335, 350}, {400, 500}, {550, 650}, {700, 800}}},
			{695, { {775, 800}}},
			{745, { {185, 400}, {650, 775}, {800, 925}}}
		}},
		//left border
		{Border::LEFT, {
			{55, { {185, 400}, {650, 775}, {800, 925}}},
			{105, { {775, 800}}},
			{185, { {235, 285}, {335, 350}, {400, 500}, {550, 650}, {700, 800}}},
			{260, { {335, 400}, {425, 500}, {550, 650}, {775, 850}}},
			{335, { {235, 285}, {400, 425}, {700, 725}, {850, 875}}},
			{415, { {185, 285}, {350, 425}, {650, 725}, {800, 875}}},
			{490, { {335, 350}, {475, 575}, {625, 650}, {775, 800}}},
			{565, { {235, 285}, {335, 500}, {550, 650}, {700, 725}, {775, 850}}},
			{645, { {725, 800}}},
			{695, { {235, 285}, {335, 350}, {700, 725}, {850, 875}}}
		}}
		});


	return;
}

/**
* @brief Function checking whether movement in certain direction is possible and adding requests to buffer if necessary
*/
bool Movement::canmove(Pacman& pacman, const Direction& dirr)
{
	//boolean value returning true if user input semi-correct (pacman origin in between walls on direction change)
	bool pathopen = true;

	//values of borders coordinates, needed to calculate the correct axis position on which pacman will move when dirr changed
	float min = 0;
	float max = 1000;

	//saving values of current pacman position so not to call getpos function 12452365 times :)
	float pacposy = pacman.getposy();
	float pacposx = pacman.getposx();

	//if checking possibility to move left
	if (dirr == Direction::LEFT)
	{
		//if pacman in the specific middle position of the map where he should be teleported from left to right 
		//(same as in the popular snake game)
		if (pacposy == 525 && pacposx == 0)
		{
			pacman.setposx(800);
			return true;
		}

		//going through border map to find all left-side borders (only ones important when want to move left)
		for (const auto& bordermap : borders)
		{
			if (bordermap.first == Border::LEFT)
			{

				//checking all left-side borders key values (x coordinates)
				for (const auto& key : bordermap.second)
				{					
					float temp = pacposx - key.first;

					//if below statement true- no correct borders will be found, force quit the loop 
					if (temp < 25)
					{
						break;
					}

					//if found left-side border key which is relevant considering current pacman position
					if (temp == 25)
					{
						for (const auto& length : key.second)
						{
							//check if there is a border in pacmans way
							if (pacposy > length.first && pacposy < length.second)
							{
								pathopen = false;
							}
						}
					}
				}
				break;
			}
		}
	}
	//same as explained for the left dirr
	else if (dirr == Direction::RIGHT)
	{
		if (pacposy == 525 && pacposx == 800)
		{
			pacman.setposx(0);
			return true;
		}
		for (const auto& bordermap : borders)
		{
			if (bordermap.first == Border::RIGHT)
			{
				for (const auto& key : bordermap.second)
				{
					float temp = key.first - pacposx;
					if (temp > 25)
					{
						break;
					}
					if (temp == 25)
					{
						for (const auto& length : key.second)
						{
							if (pacposy > length.first && pacposy < length.second)
							{
								pathopen = false;
							}
						}
					}
				}
				break;
			}
		}
	}
	//same as explained for the left dirr
	else if (dirr == Direction::UP)
	{
		for (const auto& bordermap : borders)
		{
			if (bordermap.first == Border::TOP)
			{
				for (const auto& key : bordermap.second)
				{
					float temp = pacposy - key.first;
					if (temp < 25)
					{
						break;
					}
					if (temp == 25)
					{
						for (const auto& length : key.second)
						{
							if (pacposx > length.first && pacposx < length.second)
							{
								pathopen = false;
							}
						}
					}
				}
				break;
			}
		}
	}
	//same as explained for the left dirr
	else if (dirr == Direction::DOWN)
	{
		for (const auto& bordermap : borders)
		{
			if (bordermap.first == Border::BOT)
			{
				for (const auto& key : bordermap.second)
				{
					float temp = key.first - pacposy;	
					if (temp > 25)
					{
						break;
					}
					if (temp == 25)
					{
						for (const auto& length : key.second)
						{	
							if (pacposx > length.first && pacposx < length.second)
							{
								pathopen = false;
							}	
						}
					}
				}
				break;
			}
		}		
	}

	//if pacman can move in the given direction
	if (pathopen == true)
	{
		//if pacman doesnt change the axis of movement
		if (sameaxis(pacman, dirr))
		{
			return pathopen;
		}		
		//if pacman changes the axis of movement
		else
		{
			//find axis key on which pacman will be moving and which will be added to buffer
			findcorrpos(pacman, dirr, min, max);
			//std::cout << "path open" << std::endl;

			//add found values to movement buffer
			dir_buffer.active = true;
			dir_buffer.cord = (min + max) / 2;
			dir_buffer.dir = dirr;
		}
	}
	/*else
	{
		std::cout << "path closed" << std::endl;
	}*/

	return pathopen;
}

/**
* @brief Function finding axis coordinates which will me added to movement buffer
*/
void Movement::findcorrpos(Pacman& pacman, const Direction& dirr, float& min, float& max)
{
	float pacposx = pacman.getposx();
	float pacposy = pacman.getposy();

	if (dirr == Direction::LEFT)
	{
		for (const auto& bordermap : borders)
		{
			if (bordermap.first == Border::BOT)
			{
				for (const auto& key : bordermap.second)
				{
					if (key.first < max && key.first > pacposy)
					{
						max = key.first;
					}
				}
			}
			else if (bordermap.first == Border::TOP)
			{
				for (const auto& key : bordermap.second)
				{
					if (key.first > min && key.first < pacposy)
					{
						min = key.first;
					}
				}
			}
		}
	}
	else if (dirr == Direction::RIGHT)
	{
		for (const auto& bordermap : borders)
		{
			if (bordermap.first == Border::BOT)
			{
				for (const auto& key : bordermap.second)
				{
					if (key.first < max && key.first > pacposy)
					{
						max = key.first;
					}
				}
			}
			else if (bordermap.first == Border::TOP)
			{
				for (const auto& key : bordermap.second)
				{
					if (key.first > min && key.first < pacposy)
					{
						min = key.first;
					}
				}
			}
		}
	}
	else if (dirr == Direction::UP)
	{
		for (const auto& bordermap : borders)
		{
			if (bordermap.first == Border::LEFT)
			{
				for (const auto& key : bordermap.second)
				{
					if (key.first > min && key.first < pacposx)
					{
						min = key.first;
					}
				}
			}
			else if (bordermap.first == Border::RIGHT)
			{
				for (const auto& key : bordermap.second)
				{
					if (key.first < max && key.first > pacposx)
					{
						max = key.first;
					}
				}
			}
		}
	}
	else if (dirr == Direction::DOWN)
	{
		for (const auto& bordermap : borders)
		{
			if (bordermap.first == Border::LEFT)
			{
				for (const auto& key : bordermap.second)
				{
					if (key.first > min && key.first < pacposx)
					{
						min = key.first;
					}
				}
			}
			else if (bordermap.first == Border::RIGHT)
			{
				for (const auto& key : bordermap.second)
				{
					if (key.first < max && key.first > pacposx)
					{
						max = key.first;
					}
				}
			}
		}
	}
}

/**
* @brief Function checking if current pacman position is correct so it can switch movement axis
* 
* @returns Boolean value true- if can change direction, false- if cant change direction yet
*/
bool Movement::checkcorrpos(Pacman& pacman)
{
	if (dir_buffer.dir == Direction::LEFT || dir_buffer.dir == Direction::RIGHT)
	{
		if (pacman.getposy() == dir_buffer.cord)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (pacman.getposx() == dir_buffer.cord)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

/**
* @brief Function checking if direction change will happen without changing movment axis
*/
bool Movement::sameaxis(Pacman& pacman, const Direction& dirr)
{
	Direction currdir = pacman.getdir();

	if ((currdir == Direction::LEFT && (dirr == Direction::LEFT || dirr == Direction::RIGHT)) ||
		(currdir == Direction::RIGHT && (dirr == Direction::LEFT || dirr == Direction::RIGHT)) ||
		(currdir == Direction::UP && (dirr == Direction::UP || dirr == Direction::DOWN)) ||
		(currdir == Direction::DOWN && (dirr == Direction::UP || dirr == Direction::DOWN)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
* @brief Main function managing pacman movement
*/
void Movement::movepac(Pacman& pacman, const Direction& dirr)
{	
	if (sameaxis(pacman,dirr))
	{
		if (dir_buffer.active)
		{
			if (checkcorrpos(pacman) == true)
			{
				pacman.move(dir_buffer.dir);
				dir_buffer.active = false;
			}
			else if (canmove(pacman, dirr))
			{
				pacman.move(dirr);
			}
		}
		else if (canmove(pacman, dirr))
		{
			pacman.move(dirr);
		}
	}
	else
	{
		if (canmove(pacman, dirr))
		{
			if (checkcorrpos(pacman) == true)
			{
				pacman.move(dir_buffer.dir);
				dir_buffer.active = false;
			}
			else if (canmove(pacman, pacman.getdir()))
			{
				pacman.move(pacman.getdir());
			}
		}
		else if (canmove(pacman, pacman.getdir()))
		{
			pacman.move(pacman.getdir());
		}
	}

	return;
}


void Movement::testborders()
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

void Movement::draw(sf::RenderWindow* window)
{
	window->draw(sprite);
}