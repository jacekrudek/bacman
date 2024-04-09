#include "Movement.h"


Movement::Movement()
{
	initborders();

	dir_buffer.active = false;
	dir_buffer.cord = 0;
	dir_buffer.dir = Direction::LEFT;

	testborders();
}

void Movement::initborders()
{
	////initialize border values
	//borders.insert({
	//	//top border
	//	{Border::TOP, {
	//		{186, { {54, 392}, {417, 755}}},
	//		{280, { {104, 184}, {238, 341}, {392, 418}, {471, 575}, {628, 708}}},
	//		{353, { {104, 184}, {318, 392}, {417, 496}, {628, 708}}},
	//		{430, { {260, 341}, {392, 417}, {470, 550}}},
	//		{502, { {0, 185}, {237, 261}, {550, 574}, {624, 800}}},
	//		{576, { {317, 496}}},
	//		{648, { {54, 185}, {237, 260}, {318, 393}, {417, 495}, {550, 574}, {624, 756}}},
	//		{723, { {106, 161}, {238, 341}, {392, 417}, {470, 573}, {651, 706}}},
	//		{797, { {54, 102}, {161, 185}, {318, 392}, {417, 496}, {628, 651}, {708, 755}}},
	//		{871, { {104, 339}, {392, 417}, {471, 706}}}
	//	}},
	//	//bot border
	//	{Border::BOT, {
	//		{234, { {104, 183}, {237, 341}, {471, 574}, {628, 708}}},
	//		{331, { {104, 183}, {237, 260}, {318, 496}, {551, 574}, {628, 708}}},
	//		{401, { {54, 186}, {260, 341}, {470, 551}, {624, 755}}},
	//		{479, { {317, 495}}},
	//		{548, { {0, 186}, {237, 260}, {550, 573}, {624, 800}}},
	//		{627, { {318, 496}}},
	//		{700, { {106, 184}, {239, 341}, {470, 574}, {628, 706}}},
	//		{774, { {54, 101}, {236, 260}, {318, 496}, {550, 574}, {709, 756}}},
	//		{850, { {104, 236}, {260, 339}, {471, 550}, {574, 706}}},
	//		{916, { {54, 756}}}
	//	}},
	//	//right border
	//	{Border::RIGHT, {
	//		{105, { {235, 279}, {331, 353}, {700, 723}, {850, 871}}},
	//		{161, { {723, 797}}},
	//		{238, { {234, 280}, {332, 501}, {553, 649}, {700, 722}, {774, 851}}},
	//		{318, { {331, 353}, {479, 576}, {627, 648}, {774, 795}}},
	//		{392, { {186, 282}, {353, 429}, {649, 724}, {795, 871}}},
	//		{472, { {234, 280}, {406, 430}, {701, 723}, {850, 871}}},
	//		{551, { {331, 407}, {430, 501}, {553, 649}, {774, 850}}},
	//		{628, { {234, 279}, {331, 353}, {401, 502}, {548, 649}, {700, 797}}},
	//		{709, { {774, 797}}},
	//		{755, { {186, 401}, {650, 774}, {797, 916}}}
	//	}},
	//	//left border
	//	{Border::LEFT, {
	//		{54, { {186, 402}, {649, 774}, {797, 916}}},
	//		{104, { {774, 797}}},
	//		{185, { {234, 280}, {331, 353}, {401, 502}, {548, 649}, {701, 797}}},
	//		{260, { {331, 407}, {430, 501}, {552, 649}, {775, 850}}},
	//		{341, { {234, 280}, {407, 429}, {700, 723}, {850, 871}}},
	//		{417, { {186, 282}, {353, 429}, {648, 723}, {796, 871}}},
	//		{496, { {332, 352}, {479, 577}, {626, 648}, {774, 795}}},
	//		{575, { {234, 280}, {332, 501}, {553, 649}, {700, 723}, {774, 850}}},
	//		{651, { {723, 797}}},
	//		{708, { {234, 280}, {331, 352}, {700, 723}, {850, 871}}}
	//	}}
	//	});

	borders.insert({
		//top border
		{Border::TOP, {
			{185, { {55, 385}, {415, 745}}},
			{285, { {105, 185}, {235, 335},{385, 415}, {465, 565}, {615, 695}}},
			{360, { {105, 185}, {310, 385}, {415, 490}, {615, 695}}},
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
			{105, { {235, 285}, {335, 360}, {700, 725}, {850, 875}}},
			{155, { {725, 800}}},
			{235, { {235, 285}, {335, 500}, {550, 650}, {700, 725}, {775, 850}}},
			{310, { {335, 360}, {475, 575}, {625, 650}, {775, 800}}},
			{385, { {185, 285}, {360, 425}, {650, 725}, {800, 875}}},
			{465, { {235, 285}, {400, 425}, {700, 725}, {850, 875}}},
			{540, { {335, 400}, {425, 500}, {550, 650}, {775, 850}}},
			{615, { {235, 285}, {335, 360}, {400, 500}, {550, 650}, {700, 800}}},
			{695, { {775, 800}}},
			{745, { {185, 400}, {650, 775}, {800, 925}}}
		}},
		//left border
		{Border::LEFT, {
			{55, { {185, 400}, {650, 775}, {800, 925}}},
			{105, { {775, 800}}},
			{185, { {235, 285}, {335, 360}, {400, 500}, {550, 650}, {700, 800}}},
			{260, { {335, 400}, {425, 500}, {550, 650}, {775, 850}}},
			{335, { {235, 285}, {400, 425}, {700, 725}, {850, 875}}},
			{415, { {185, 285}, {360, 425}, {650, 725}, {800, 875}}},
			{490, { {335, 360}, {475, 575}, {625, 650}, {775, 800}}},
			{565, { {235, 285}, {335, 500}, {550, 650}, {700, 725}, {775, 850}}},
			{645, { {725, 800}}},
			{695, { {235, 285}, {335, 360}, {700, 725}, {850, 875}}}
		}}
		});


	return;
}

bool Movement::canmove(Pacman& pacman, const Direction& dirr)
{
	bool pathopen = true;
	float min = 0;
	float max = 1000;

	if (dirr == Direction::LEFT)
	{
		for (const auto& bordermap : borders)
		{
			if (bordermap.first == Border::LEFT)
			{
				for (const auto& key : bordermap.second)
				{					
					float temp = pacman.getposx() - key.first;
					if (temp < 25)
					{
						break;
					}
					if (temp == 25)
					{
						for (const auto& length : key.second)
						{
							/*if (length.second > min && length.second < pacman.getposy())
							{
								min = length.second;
							}
							if (length.first < max && length.first > pacman.getposy())
							{
								max = length.first;
							}*/
							if (pacman.getposy() > length.first && pacman.getposy() < length.second)
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
	else if (dirr == Direction::RIGHT)
	{
		for (const auto& bordermap : borders)
		{
			if (bordermap.first == Border::RIGHT)
			{
				for (const auto& key : bordermap.second)
				{
					float temp = key.first - pacman.getposx();
					//if (temp < 27 && temp > 0)
					if (temp > 25)
					{
						break;
					}
					if (temp == 25)
					{
						for (const auto& length : key.second)
						{
							/*if (length.second > min && length.second < pacman.getposy())
							{
								min = length.second;
							}
							if (length.first < max && length.first > pacman.getposy())
							{
								max = length.first;
							}*/
							if (pacman.getposy() > length.first && pacman.getposy() < length.second)
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
	else if (dirr == Direction::UP)
	{
		for (const auto& bordermap : borders)
		{
			if (bordermap.first == Border::TOP)
			{
				for (const auto& key : bordermap.second)
				{
					float temp = pacman.getposy() - key.first;
					if (temp < 25)
					{
						break;
					}
					if (temp == 25)
					{
						for (const auto& length : key.second)
						{
							/*if (length.second > min && length.second < pacman.getposx())
							{
								min = length.second;
							}
							if (length.first < max && length.first > pacman.getposx())
							{
								max = length.first;
							}*/
							if (pacman.getposx() > length.first && pacman.getposx() < length.second)
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
	else if (dirr == Direction::DOWN)
	{
		for (const auto& bordermap : borders)
		{
			if (bordermap.first == Border::BOT)
			{
				for (const auto& key : bordermap.second)
				{
					float temp = key.first - pacman.getposy();	
					if (temp > 25)
					{
						break;
					}
					if (temp == 25)
					{
						for (const auto& length : key.second)
						{	
							/*if (length.second > min && length.second < pacman.getposx())
							{
								min = length.second;
							}
							if (length.first < max && length.first > pacman.getposx())
							{
								max = length.first;
							}*/
							if (pacman.getposx() > length.first && pacman.getposx() < length.second)
							//if (pacman.getposx() != (length.first + length.second)/2)
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
	if (pathopen == true)
	{
		if ((pacman.getdir() == Direction::LEFT && (dirr == Direction::LEFT || dirr == Direction::RIGHT)) ||
			(pacman.getdir() == Direction::RIGHT && (dirr == Direction::LEFT || dirr == Direction::RIGHT)) ||
			(pacman.getdir() == Direction::UP && (dirr == Direction::UP || dirr == Direction::DOWN)) ||
			(pacman.getdir() == Direction::DOWN && (dirr == Direction::UP || dirr == Direction::DOWN)))
		{
			return pathopen;
		}
		if (dirr == Direction::LEFT)
		{
			for (const auto& bordermap : borders)
			{
				if (bordermap.first == Border::BOT)
				{
					for (const auto& key : bordermap.second)
					{
						if (key.first < max && key.first > pacman.getposy())
						{
							max = key.first;
						}
					}
				}
				else if (bordermap.first == Border::TOP)
				{
					for (const auto& key : bordermap.second)
					{
						if (key.first > min && key.first < pacman.getposy())
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
						if (key.first < max && key.first > pacman.getposy())
						{
							max = key.first;
						}
					}
				}
				else if (bordermap.first == Border::TOP)
				{
					for (const auto& key : bordermap.second)
					{
						if (key.first > min && key.first < pacman.getposy())
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
						if (key.first > min && key.first < pacman.getposx())
						{
							min = key.first;
						}
					}
				}
				else if (bordermap.first == Border::RIGHT)
				{
					for (const auto& key : bordermap.second)
					{
						if (key.first < max && key.first > pacman.getposx())
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
						if (key.first > min && key.first < pacman.getposx())
						{
							min = key.first;
						}
					}
				}
				else if (bordermap.first == Border::RIGHT)
				{
					for (const auto& key : bordermap.second)
					{
						if (key.first < max && key.first > pacman.getposx())
						{
							max = key.first;
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
		if ((pacman.getdir() != Direction::LEFT && (dirr == Direction::LEFT || dirr == Direction::RIGHT)) ||
			(pacman.getdir() != Direction::RIGHT && (dirr == Direction::LEFT || dirr == Direction::RIGHT)) ||
			(pacman.getdir() != Direction::UP && (dirr == Direction::UP || dirr == Direction::DOWN)) ||
			(pacman.getdir() != Direction::DOWN && (dirr == Direction::UP || dirr == Direction::DOWN)))
		{
			dir_buffer.active = true;
			dir_buffer.cord = (min + max) / 2;
			dir_buffer.dir = dirr;
		}
		break;
	case false:
		std::cout << "path closed" << std::endl;
		break;
	}

	return pathopen;
}

//void Movement::checkcorrpos(Pacman& pacman, const Direction& dirr, bool& isok)
//{
//	if (dirr == Direction::LEFT)
//	{
//		for (const auto& bordermap : borders)
//		{
//			if (bordermap.first == Border::TOP)
//			{
//			}
//			else if (bordermap.first == Border::BOT)
//			{
//			}
//		}
//	}
//}

//bool Movement::checkcorrpos(Pacman& pacman, const Direction& dirr)
//{
//	bool isok = false;
//
//	int min_cord = std::numeric_limits<int>::max();
//	int max_cord = 0;
//
//	int min = std::numeric_limits<int>::max();
//	int max = std::numeric_limits<int>::max();
//
//	if (dirr == Direction::LEFT)
//	{
//		for (const auto& bordermap : borders)
//		{
//			if (bordermap.first == Border::TOP)
//			{
//				for (const auto& key : bordermap.second)
//				{
//					float temp = pacman.getposy() - key.first;
//					if (temp < 35 && temp > 0)
//					{
//						min_cord = key.first;
//
//						//if (pacman.getdir() == Direction::DOWN)
//						//{
//							dir_buffer.active = true;
//							dir_buffer.dir = Direction::LEFT;
//						//}
//					}
//				}
//			}
//			else if (bordermap.first == Border::BOT)
//			{
//				for (const auto& key : bordermap.second)
//				{
//					float temp = key.first - pacman.getposy();
//					if (temp < 35 && temp > 0)
//					{
//						max_cord = key.first;
//
//						//if (pacman.getdir() == Direction::UP)
//						//{
//							dir_buffer.active = true;
//							dir_buffer.dir = Direction::LEFT;
//						//}
//					}
//				}
//			}
//		}
//		//if (min_cord != std::numeric_limits<int>::max() && max_cord != 0)
//		if (dir_buffer.active == true)
//		{
//			float temp = (min_cord + max_cord) / 2;
//			//pacman.setposy(temp);
//			dir_buffer.cord = temp;
//			isok = true;
//		}
//	}
//	else if (dirr == Direction::RIGHT)
//	{
//		for (const auto& bordermap : borders)
//		{
//			if (bordermap.first == Border::TOP)
//			{
//				for (const auto& key : bordermap.second)
//				{
//					float temp = pacman.getposy() - key.first;
//					if (temp < 35 && temp > 0)
//					{
//						min_cord = key.first;
//
//						//if (pacman.getdir() == Direction::DOWN)
//						//{
//							dir_buffer.active = true;
//							dir_buffer.dir = Direction::RIGHT;
//						//}
//					}
//				}
//			}
//			else if (bordermap.first == Border::BOT)
//			{
//				for (const auto& key : bordermap.second)
//				{
//					float temp = key.first - pacman.getposy();
//					if (temp < 35 && temp > 0)
//					{
//						max_cord = key.first;
//
//						//if (pacman.getdir() == Direction::UP)
//						//{
//							dir_buffer.active = true;
//							dir_buffer.dir = Direction::RIGHT;
//						//}
//					}
//				}
//			}
//		}
//		//if (min_cord != std::numeric_limits<int>::max() && max_cord != 0)
//		if (dir_buffer.active == true)
//		{
//			float temp = (min_cord + max_cord) / 2;
//			//pacman.setposy(temp);
//			dir_buffer.cord = temp;
//			isok = true;
//		}
//	}
//	else if (dirr == Direction::UP)
//	{
//		for (const auto& bordermap : borders)
//		{
//			if (bordermap.first == Border::RIGHT)
//			{
//				for (const auto& key : bordermap.second)
//				{
//					float temp = key.first - pacman.getposx();
//					if (temp < 35 && temp > 0)
//					{
//						min_cord = key.first;
//
//						//if (pacman.getdir() == Direction::LEFT)
//						//{
//							dir_buffer.active = true;
//							dir_buffer.dir = Direction::UP;
//						//}
//					}
//				}
//			}
//			else if (bordermap.first == Border::LEFT)
//			{
//				for (const auto& key : bordermap.second)
//				{
//					float temp = pacman.getposx() - key.first;
//					if (temp < 35 && temp > 0)
//					{
//						max_cord = key.first;
//
//						//if (pacman.getdir() == Direction::RIGHT)
//						//{
//							dir_buffer.active = true;
//							dir_buffer.dir = Direction::UP;
//						//}
//					}
//				}
//			}
//		}
//		//if (min_cord != std::numeric_limits<int>::max() && max_cord != 0)
//		if (dir_buffer.active == true)
//		{
//			float temp = (min_cord + max_cord) / 2;
//			//pacman.setposx(temp);
//			dir_buffer.cord = temp;
//			isok = true;
//		}
//	}
//	else if (dirr == Direction::DOWN)
//	{
//		for (const auto& bordermap : borders)
//		{
//			if (bordermap.first == Border::RIGHT)
//			{
//				for (const auto& key : bordermap.second)
//				{
//					float temp = key.first - pacman.getposx();
//					if (temp < 35 && temp > 0)
//					{
//						min_cord = key.first;
//
//						//if (pacman.getdir() == Direction::LEFT)
//						//{
//							dir_buffer.active = true;
//							dir_buffer.dir = Direction::DOWN;
//						//}
//					}
//				}
//			}
//			else if (bordermap.first == Border::LEFT)
//			{
//				for (const auto& key : bordermap.second)
//				{
//					float temp = pacman.getposx() - key.first;
//					if (temp < 35 && temp > 0)
//					{
//						max_cord = key.first;
//
//						//if (pacman.getdir() == Direction::RIGHT)
//						//{
//							dir_buffer.active = true;
//							dir_buffer.dir = Direction::DOWN;
//						//}
//					}
//				}
//			}
//		}
//		//if (min_cord != std::numeric_limits<int>::max() && max_cord != 0)
//		if (dir_buffer.active == true)
//		{
//			float temp = (min_cord + max_cord) / 2;
//			//pacman.setposx(temp);
//			dir_buffer.cord = temp;			
//			//isok = true;			
//		}
//	}
//
//	return isok;
//}

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


void Movement::movepac(Pacman& pacman, const Direction& dirr)
{	
	if ((pacman.getdir() == Direction::LEFT && (dirr == Direction::LEFT || dirr == Direction::RIGHT)) ||
		(pacman.getdir() == Direction::RIGHT && (dirr == Direction::LEFT || dirr == Direction::RIGHT)) ||
		(pacman.getdir() == Direction::UP && (dirr == Direction::UP || dirr == Direction::DOWN)) ||
		(pacman.getdir() == Direction::DOWN && (dirr == Direction::UP || dirr == Direction::DOWN)))
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



	//if ((pacman.getdir() == Direction::LEFT && (dirr == Direction::LEFT || dirr == Direction::RIGHT)) ||
	//	(pacman.getdir() == Direction::RIGHT && (dirr == Direction::LEFT || dirr == Direction::RIGHT)) ||
	//	(pacman.getdir() == Direction::UP && (dirr == Direction::UP || dirr == Direction::DOWN)) ||
	//	(pacman.getdir() == Direction::DOWN && (dirr == Direction::UP || dirr == Direction::DOWN))
	//	&& canmove(pacman, dirr))
	//{
	//	pacman.move(dirr);
	//}
	////if input ok but not yet in perfect position
	//else if (canmove(pacman, dirr))
	//{
	//	pacman.move(dirr);
	//}
	//else
	//{

	//}
	//if (canmove(pacman, pacman.getdir()))
	//{
	//	pacman.move(pacman.getdir());
	//}
	////if new input
	//if (dirr != pacman.getdir() && dirr != dir_buffer.dir)
	//{
	//	if (canmove(pacman, dirr) == true)
	//	{
	//		if (checkcorrpos(pacman, dirr) == true)
	//		{
	//			pacman.move(dirr);
	//		}

	//		/*if ((pacman.getdir() == Direction::LEFT && (dirr == Direction::LEFT || dirr == Direction::RIGHT)) ||
	//			(pacman.getdir() == Direction::RIGHT && (dirr == Direction::LEFT || dirr == Direction::RIGHT)) ||
	//			(pacman.getdir() == Direction::UP && (dirr == Direction::UP || dirr == Direction::DOWN)) ||
	//			(pacman.getdir() == Direction::DOWN && (dirr == Direction::UP || dirr == Direction::DOWN)))
	//		{
	//			if (dir_buffer.active == false)
	//			{
	//				pacman.move(dirr);
	//			}
	//			else
	//			{
	//				if (dir_buffer.dir == Direction::LEFT || dir_buffer.dir == Direction::RIGHT)
	//				{
	//					if ((dir_buffer.cord - pacman.getposy())<5 && (dir_buffer.cord - pacman.getposy())>-5)
	//					{
	//						pacman.setposy(dir_buffer.cord);
	//						pacman.move(dir_buffer.dir);
	//						dir_buffer.active = false;
	//					}
	//					else
	//					{
	//						pacman.move(dirr);
	//					}
	//				}
	//				else
	//				{
	//					if ((dir_buffer.cord - pacman.getposx()) < 5 && (dir_buffer.cord - pacman.getposx()) > -5)
	//					{
	//						pacman.setposx(dir_buffer.cord);
	//						pacman.move(dir_buffer.dir);
	//						dir_buffer.active = false;
	//					}
	//					else
	//					{
	//						pacman.move(dirr);
	//					}
	//				}

	//			}
	//		}
	//		else
	//		{
	//			bool isok = false;
	//			setcorrpos(pacman, dirr, isok);
	//			if (dir_buffer.dir == Direction::LEFT || dir_buffer.dir == Direction::RIGHT)
	//			{
	//				if ((dir_buffer.cord - pacman.getposy()) < 5 && (dir_buffer.cord - pacman.getposy()) > -5)
	//				{
	//					pacman.setposy(dir_buffer.cord);
	//					pacman.move(dir_buffer.dir);
	//					dir_buffer.active = false;
	//				}
	//				else
	//				{
	//					pacman.move(pacman.getdir());
	//				}
	//			}
	//			else
	//			{
	//				if ((dir_buffer.cord - pacman.getposx()) < 5 && (dir_buffer.cord - pacman.getposx()) > -5)
	//				{
	//					pacman.setposx(dir_buffer.cord);
	//					pacman.move(dir_buffer.dir);
	//					dir_buffer.active = false;
	//				}
	//				else
	//				{
	//					pacman.move(pacman.getdir());
	//				}
	//			}
	//		}*/
	//	}
	//}
	////if focusing on input in buffer, no new inputs or the same input that in buffer
	//else if (dir_buffer.active == true && (dirr == pacman.getdir() || dirr == dir_buffer.dir))
	//{

	//}
	//if ((pacman.getdir() == Direction::LEFT && (dirr == Direction::LEFT || dirr == Direction::RIGHT)) ||
	//	(pacman.getdir() == Direction::RIGHT && (dirr == Direction::LEFT || dirr == Direction::RIGHT)) ||
	//	(pacman.getdir() == Direction::UP && (dirr == Direction::UP || dirr == Direction::DOWN)) ||
	//	(pacman.getdir() == Direction::DOWN && (dirr == Direction::UP || dirr == Direction::DOWN)))
	//{
	//	if (canmove(pacman, dirr))
	//	{
	//		pacman.move(dirr);
	//	}
	//}
	////if no new inputs and possible to move in current direction
	//else if (dirr == pacman.getdir() && canmove(pacman, pacman.getdir()) && dir_buffer.active == false)
	//{
	//	pacman.move(dirr);
	//}
	////if new input
	//else
	//{
	//	if (dir_buffer.active == true)
	//	{
	//		/*if (checkcorrpos(pacman, dir_buffer.dir) == true)
	//		{
	//			pacman.move(dirr);
	//			dir_buffer.active = false;
	//		}*/
	//		if (dir_buffer.dir == Direction::LEFT || dir_buffer.dir == Direction::RIGHT)
	//		{
	//			if (pacman.getposy() == dir_buffer.cord)
	//			{
	//				pacman.move(dir_buffer.dir);
	//				dir_buffer.active = false;
	//			}
	//			else if (canmove(pacman, pacman.getdir()))
	//			{
	//				pacman.move(pacman.getdir());
	//			}
	//			/*if (pacman.getposy() < dir_buffer.cord)
	//			{
	//				dir_buffer.active = false;
	//			}*/
	//			if (pacman.getdir() == Direction::UP)
	//			{
	//				if (pacman.getposy() < dir_buffer.cord)
	//				{
	//					dir_buffer.active = false;
	//				}
	//			}
	//			else if (pacman.getdir() == Direction::DOWN)
	//			{
	//				if (pacman.getposy() > dir_buffer.cord)
	//				{
	//					dir_buffer.active = false;
	//				}
	//			}
	//		}
	//		if (dir_buffer.dir == Direction::UP || dir_buffer.dir == Direction::DOWN)
	//		{
	//			if (pacman.getposx() == dir_buffer.cord)
	//			{
	//				pacman.move(dir_buffer.dir);
	//				dir_buffer.active = false;
	//			}
	//			else if (canmove(pacman, pacman.getdir()))
	//			{
	//				pacman.move(pacman.getdir());
	//			}
	//			if (pacman.getdir() == Direction::LEFT)
	//			{
	//				if (pacman.getposx() < dir_buffer.cord)
	//				{
	//					dir_buffer.active = false;
	//				}
	//			}
	//			else if (pacman.getdir() == Direction::RIGHT)
	//			{
	//				if (pacman.getposx() > dir_buffer.cord)
	//				{
	//					dir_buffer.active = false;
	//				}
	//			}
	//		}
	//		

	//		/*if ((pacman.getdir() == Direction::LEFT && (dirr == Direction::LEFT || dirr == Direction::RIGHT)) ||
	//			(pacman.getdir() == Direction::RIGHT && (dirr == Direction::LEFT || dirr == Direction::RIGHT)) ||
	//			(pacman.getdir() == Direction::UP && (dirr == Direction::UP || dirr == Direction::DOWN)) ||
	//			(pacman.getdir() == Direction::DOWN && (dirr == Direction::UP || dirr == Direction::DOWN)))
	//		{
	//			if (dir_buffer.active == false)
	//			{
	//				pacman.move(dirr);
	//			}
	//			else
	//			{
	//				if (dir_buffer.dir == Direction::LEFT || dir_buffer.dir == Direction::RIGHT)
	//				{
	//					if ((dir_buffer.cord - pacman.getposy())<5 && (dir_buffer.cord - pacman.getposy())>-5)
	//					{
	//						pacman.setposy(dir_buffer.cord);
	//						pacman.move(dir_buffer.dir);
	//						dir_buffer.active = false;
	//					}
	//					else
	//					{
	//						pacman.move(dirr);
	//					}
	//				}
	//				else
	//				{
	//					if ((dir_buffer.cord - pacman.getposx()) < 5 && (dir_buffer.cord - pacman.getposx()) > -5)
	//					{
	//						pacman.setposx(dir_buffer.cord);
	//						pacman.move(dir_buffer.dir);
	//						dir_buffer.active = false;
	//					}
	//					else
	//					{
	//						pacman.move(dirr);
	//					}
	//				}

	//			}
	//		}
	//		else
	//		{
	//			bool isok = false;
	//			setcorrpos(pacman, dirr, isok);
	//			if (dir_buffer.dir == Direction::LEFT || dir_buffer.dir == Direction::RIGHT)
	//			{
	//				if ((dir_buffer.cord - pacman.getposy()) < 5 && (dir_buffer.cord - pacman.getposy()) > -5)
	//				{
	//					pacman.setposy(dir_buffer.cord);
	//					pacman.move(dir_buffer.dir);
	//					dir_buffer.active = false;
	//				}
	//				else
	//				{
	//					pacman.move(pacman.getdir());
	//				}
	//			}
	//			else
	//			{
	//				if ((dir_buffer.cord - pacman.getposx()) < 5 && (dir_buffer.cord - pacman.getposx()) > -5)
	//				{
	//					pacman.setposx(dir_buffer.cord);
	//					pacman.move(dir_buffer.dir);
	//					dir_buffer.active = false;
	//				}
	//				else
	//				{
	//					pacman.move(pacman.getdir());
	//				}
	//			}
	//		}*/

	//	}
	//	else
	//	{
	//		if (canmove(pacman, dirr) == true)
	//		{
	//			checkcorrpos(pacman, dirr);
	//			if (dir_buffer.dir == Direction::LEFT || dir_buffer.dir == Direction::RIGHT)
	//			{
	//				if (pacman.getposy() == dir_buffer.cord)
	//				{
	//					pacman.move(dir_buffer.dir);
	//					dir_buffer.active = false;
	//				}
	//				else if (canmove(pacman, pacman.getdir()))
	//				{
	//					pacman.move(pacman.getdir());
	//				}
	//				if (pacman.getposy() < dir_buffer.cord)
	//				{
	//					dir_buffer.active = false;
	//				}
	//			}
	//			if (dir_buffer.dir == Direction::UP || dir_buffer.dir == Direction::DOWN)
	//			{
	//				if (pacman.getposx() == dir_buffer.cord)
	//				{
	//					pacman.move(dir_buffer.dir);
	//					dir_buffer.active = false;
	//				}
	//				else if (canmove(pacman, pacman.getdir()))
	//				{
	//					pacman.move(pacman.getdir());
	//				}
	//				if (pacman.getposx() < dir_buffer.cord)
	//				{
	//					dir_buffer.active = false;
	//				}
	//			}
	//			
	//		}
	//	}
	//}
	/*else if (canmove(pacman, pacman.getdir()) == true)
	{
		pacman.move(pacman.getdir());
	}*/

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