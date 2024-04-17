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
	initvertexes();

	dir_buffer.active = false;
	dir_buffer.cord = 0;
	dir_buffer.dir = Direction::LEFT;

	//sf::Vector2f start = { 10,10 };
	//sf::Vector2f end = { 10,10 };


	//dijkstra(start, end);
	
	//testborders();
	//testvertexes();
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
* @brief Function initializing all vertex values
*/
void Movement::initvertexes()
{
	/*vertexes = {
		{80, 210},
		{210, 210},
		{360, 210},
		{440, 210},
		{590, 210},
		{720, 210},

		{80, 310},
		{210, 310},
		{285, 310},
		{360, 310},
		{440, 310},
		{515, 310},
		{590, 310},
		{720, 310},

		{80, 375},
		{210, 375},
		{285, 375},
		{360, 375},
		{440, 375},
		{515, 375},
		{590, 375},
		{720, 375},

		{285, 450},
		{360, 450},
		{440, 450},
		{515, 450},
		{210, 525},
		{285, 525},
		{515, 525},
		{590, 525},

		{285, 600},
		{515, 600},

		{80, 675},
		{210, 675},
		{285, 675},
		{360, 675},
		{440, 675},
		{515, 675},
		{590, 675},
		{720, 675},

		{80, 750},
		{130, 750},
		{210, 750},
		{285, 750},
		{360, 750},
		{440, 750},
		{515, 750},
		{590, 750},
		{670, 750},
		{720, 750},

		{80, 825},
		{130, 825},
		{210, 825},
		{285, 825},
		{360, 825},
		{440, 825},
		{515, 825},
		{590, 825},
		{670, 825},
		{720, 825},

		{80, 900},
		{360, 900},
		{440, 900},
		{720, 900}
	};

	distances =
	{
		{1, {{2, 130},{7, 100}}},
		{2, {{8, 100}, {3, 150}}},
		{3, {{10, 100}}},
		{7, {{8, 130}, {15, 65}}},
		{8, {{9, 75}, {16, 65}}},
		{15, {{16, 130}}},
		{9, {{17, 65}, {10, 75}}},
		{10, {{11, 80}}},
		{11, {{4, 100}, {12, 75}}},
		{4, {{5, 150}}},
		{5, {{13, 100}, {6, 130}}},
		{6, {{14, 100}}},
		{12, {{13, 75}, {20, 65}}},
		{13, {{14, 130}, {21, 65}}},
		{14, {{22, 65}}},
		{16, {{27, 150}}},
		{17, {{18, 75}}},
		{18, {{24, 75}}},
		{19, {{25, 75}}},
		{20, {{19, 75}}},
		{22, {{21, 130}}},
		{21, {{30, 150}}},
		{23, {{24, 75},{28,75}}},
		{24, {{25, 80}}},
		{25, {{26, 75}}},
		{26, {{29, 75}}},
		{27, {{34, 150}, {28, 75}}},
		{28, {{31, 75}}},
		{31, {{35, 75}, {32, 220}}},
		{32, {{38, 75}, {29, 75}}},
		{29, {{30, 75}}},
		{30, {{39, 150}}},
		{33, {{41, 75}, {34, 130}}},
		{34, {{43, 75}, {35, 75}}},
		{35, {{36, 75}}},
		{36, {{45, 75}}},
		{37, {{38, 75}, {46, 75}}},
		{38, {{39, 75}}},
		{39, {{40, 130}, {48, 75}}},
		{40, {{50, 75}}},
		{41, {{42, 45}}},
		{42, {{52, 75}}},
		{43, {{44, 75}, {53, 75}}},
		{44, {{45, 75}, {54, 75}}},
		{45, {{46, 80}}},
		{46, {{47, 75}}},
		{47, {{48, 75}, {57, 75}}},
		{48, {{58, 75}}},
		{49, {{50, 45}, {59, 75}}},
		{51, {{52, 45}, {61, 75}}},
		{52, {{53, 75}}},
		{54, {{55, 75}}},
		{55, {{62, 75}}},
		{56, {{57, 75}, {63, 75}}},
		{58, {{59, 85}}},
		{59, {{60, 45}}},
		{60, {{64, 75}}},
		{61, {{62, 280}}},
		{62, {{63, 80}}},
		{63, {{64, 280}}}
	};*/

ghost1vertexes = {
	{80, 210},
	{360, 210},
	{360, 310},
	{285, 310},
	{285, 375},
	{360, 375},
	{360, 450},
	{285, 450},
	{285, 525},
	{210, 525},
	{210, 375},
	{80, 375}
};

ghost2vertexes = {
	{515, 375},
	{515, 310},
	{440, 310},
	{440, 210},
	{720, 210},
	{720, 375},
	{590, 375},
	{590, 525},
	{515, 525},
	{515, 450},
	{440, 450},
	{440, 375}
};

ghost3vertexes = {
	{360, 900},
	{80, 900},
	{80, 825},
	{125, 825},
	{125, 750},
	{80, 750},
	{80, 675},
	{360, 675},
	{360, 750},
	{285, 750},
	{285, 825},
	{360, 825}
};

ghost4vertexes = {
	{590, 675},
	{440, 675},
	{440, 750},
	{515, 750},
	{515, 825},
	{440, 825},
	{440, 900},
	{720, 900},
	{720, 825},
	{675, 825},
	{675, 750},
	{720, 750},
	{720, 675}
};

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

bool Movement::colision(Pacman& pacman, Ghost& ghost)
{
	float pacposx = pacman.getposx();
	float pacposy = pacman.getposy();
	float ghostposx = ghost.getposx();
	float ghostposy = ghost.getposy();

	if (pacposx < ghostposx + 21 && pacposx > ghostposx - 21 && 
		pacposy < ghostposy + 21 && pacposy > ghostposy - 21)
	{
		return true;
	}

	return false;
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

void Movement::moveghost(Ghost& ghost)
{
	int ghost_index = ghost.getindex();

	//saving values of current pacman position so not to call getpos function 12452365 times :)
	float ghostposy = ghost.getposy();
	float ghostposx = ghost.getposx();

	bool changeddir = false;

	if (ghost_index == 1)
	{
		for (int i = 0; i < ghost1vertexes.size(); i++)
		{
			if (ghostposx == ghost1vertexes[i].first && ghostposy == ghost1vertexes[i].second)
			{
				switch (i)
				{
				case 0:
				case 4:
					ghost.move(Direction::RIGHT);
					break;
				case 1:
				case 3:
				case 5:
				case 7:
					ghost.move(Direction::DOWN);
					break;
				case 2:
				case 6:
				case 8:
				case 10:
					ghost.move(Direction::LEFT);
					break;
				case 9:
				case 11:
					ghost.move(Direction::UP);
					break;
				}
				changeddir = true;
				break;
			}
		}
		if (changeddir == false)
		{
			ghost.move(ghost.getdir());
		}
	}
	else if (ghost_index == 2)
	{
		for (int i = 0; i < ghost2vertexes.size(); i++)
		{
			if (ghostposx == ghost2vertexes[i].first && ghostposy == ghost2vertexes[i].second)
			{
				switch (i)
				{
				case 0:
				case 2:
				case 8:
				case 10:
					ghost.move(Direction::UP);
					break;
				case 1:
				case 5:
				case 7:
				case 9:
					ghost.move(Direction::LEFT);
					break;
				case 3:
				case 11:
					ghost.move(Direction::RIGHT);
					break;
				case 4:
				case 6:
					ghost.move(Direction::DOWN);
					break;
				}
				changeddir = true;
				break;
			}
		}
		if (changeddir == false)
		{
			ghost.move(ghost.getdir());
		}
	}
	else if (ghost_index == 3)
	{
		for (int i = 0; i < ghost3vertexes.size(); i++)
		{
			if (ghostposx == ghost3vertexes[i].first && ghostposy == ghost3vertexes[i].second)
			{
				switch (i)
				{
				case 0:
				case 4:
				case 8:
					ghost.move(Direction::LEFT);
					break;
				case 1:
				case 3:
				case 5:
					ghost.move(Direction::UP);
					break;
				case 2:
				case 6:
				case 10:
					ghost.move(Direction::RIGHT);
					break;
				case 7:
				case 9:
				case 11:
					ghost.move(Direction::DOWN);
					break;
				}
				changeddir = true;
				break;
			}
		}
		if (changeddir == false)
		{
			ghost.move(ghost.getdir());
		}
	}
	else if (ghost_index == 4)
	{
		for (int i = 0; i < ghost4vertexes.size(); i++)
		{
			if (ghostposx == ghost4vertexes[i].first && ghostposy == ghost4vertexes[i].second)
			{
				switch (i)
				{
				case 0:
				case 4:
				case 8:
				case 12:
					ghost.move(Direction::LEFT);
					break;
				case 1:
				case 3:
				case 5:
					ghost.move(Direction::DOWN);
					break;
				case 2:
				case 6:
				case 10:
					ghost.move(Direction::RIGHT);
					break;
				case 7:
				case 9:
				case 11:
					ghost.move(Direction::UP);
					break;
				}
				changeddir = true;
				break;
			}
		}
		if (changeddir == false)
		{
			ghost.move(ghost.getdir());
		}
	}
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

//void Movement::testvertexes()
//{
//	sf::Image image;
//	image.create(800, 1000, sf::Color::Transparent);
//
//	for (const auto& values : vertexes)
//	{
//		image.setPixel(values.first, values.second, sf::Color::Green);
//	}
//
//	texture.loadFromImage(image);
//	sprite.setTexture(texture);
//
//	return;
//}
//
//void Movement::checkvertex(Pacman& pacman)
//{
//	float pacposx = pacman.getposx();
//	float pacposy = pacman.getposy();
//
//	for (const auto& coords : vertexes)
//	{
//		if ((coords.first > pacposx - 25 && coords.first < pacposx + 25) ||
//			(coords.second > pacposy - 25 && coords.second < pacposy + 25))
//		{
//			sf::Vector2f lastvertex;
//			lastvertex.x = coords.first;
//			lastvertex.y = coords.second;
//
//			pacman.setlastvertex(lastvertex);
//		}
//	}
//}
//
//void Movement::dijkstra(sf::Vector2f& start, sf::Vector2f& finish)
//{
//	int a = findvertexindex(start);
//	int b = findvertexindex(finish);
//
//	std::vector<bool> visited;
//
//	//a, shortest distance from a, previous vertex
//	std::map<int, std::pair<int, int>> answer;
//
//	for (int i = 0; i < 64; i++)
//	{
//		visited.push_back(false);
//		answer[i+1] = { INT_MAX, INT_MAX };
//
//		if (i + 1 == a)
//		{
//			answer[i + 1] = { 0, INT_MAX };
//		}
//	}
//
//	for (const auto& outer : distances)
//	{
//		for (const auto& inner : outer.second)
//		{
//			visited[outer.first - 1] = true;
//
//			if (visited[inner.first] == true)
//			{
//				continue;
//			}
//
//
//		}		
//	}
//
//}
//
//int Movement::findvertexindex( sf::Vector2f& vertex)
//{
//	for (int i=0; i<vertexes.size(); i++)
//	{
//		if (vertexes[i].first == vertex.x && vertexes[i].second == vertex.y)
//		{
//			return i+1;
//		}
//	}
//}

//bool Movement::canmove(Ghost& ghost)
//{
//	//boolean value returning true if user input semi-correct (pacman origin in between walls on direction change)
//	bool pathopen = true;
//
//	//values of borders coordinates, needed to calculate the correct axis position on which pacman will move when dirr changed
//	float min = 0;
//	float max = 1000;
//
//	Direction currdir = ghost.getdir();
//
//	//saving values of current pacman position so not to call getpos function 12452365 times :)
//	float ghostposy = ghost.getposy();
//	float ghostposx = ghost.getposx();
//
//	//if checking possibility to move left
//	if (currdir == Direction::LEFT)
//	{
//		//going through border map to find all left-side borders (only ones important when want to move left)
//		for (const auto& bordermap : borders)
//		{
//			if (bordermap.first == Border::LEFT)
//			{
//
//				//checking all left-side borders key values (x coordinates)
//				for (const auto& key : bordermap.second)
//				{
//					float temp = ghostposx - key.first;
//
//					//if below statement true- no correct borders will be found, force quit the loop 
//					if (temp < 25)
//					{
//						break;
//					}
//
//					//if found left-side border key which is relevant considering current pacman position
//					if (temp == 25)
//					{
//						for (const auto& length : key.second)
//						{
//							//check if there is a border in pacmans way
//							if (ghostposy > length.first && ghostposy < length.second)
//							{
//								pathopen = false;
//							}
//						}
//					}
//				}
//				break;
//			}
//		}
//	}
//	//same as explained for the left dirr
//	else if (currdir == Direction::RIGHT)
//	{
//		for (const auto& bordermap : borders)
//		{
//			if (bordermap.first == Border::RIGHT)
//			{
//				for (const auto& key : bordermap.second)
//				{
//					float temp = key.first - ghostposx;
//					if (temp > 25)
//					{
//						break;
//					}
//					if (temp == 25)
//					{
//						for (const auto& length : key.second)
//						{
//							if (ghostposy > length.first && ghostposy < length.second)
//							{
//								pathopen = false;
//							}
//						}
//					}
//				}
//				break;
//			}
//		}
//	}
//	//same as explained for the left dirr
//	else if (currdir == Direction::UP)
//	{
//		for (const auto& bordermap : borders)
//		{
//			if (bordermap.first == Border::TOP)
//			{
//				for (const auto& key : bordermap.second)
//				{
//					float temp = ghostposy - key.first;
//					if (temp < 25)
//					{
//						break;
//					}
//					if (temp == 25)
//					{
//						for (const auto& length : key.second)
//						{
//							if (ghostposx > length.first && ghostposx < length.second)
//							{
//								pathopen = false;
//							}
//						}
//					}
//				}
//				break;
//			}
//		}
//	}
//	//same as explained for the left dirr
//	else if (currdir == Direction::DOWN)
//	{
//		for (const auto& bordermap : borders)
//		{
//			if (bordermap.first == Border::BOT)
//			{
//				for (const auto& key : bordermap.second)
//				{
//					float temp = key.first - ghostposy;
//					if (temp > 25)
//					{
//						break;
//					}
//					if (temp == 25)
//					{
//						for (const auto& length : key.second)
//						{
//							if (ghostposx > length.first && ghostposx < length.second)
//							{
//								pathopen = false;
//							}
//						}
//					}
//				}
//				break;
//			}
//		}
//	}
//
//	return pathopen;
//}



void Movement::draw(sf::RenderWindow* window)
{
	window->draw(sprite);
}