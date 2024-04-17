#pragma once
#ifndef MENU_H
#define MENU_H

#include "libraries.h"

#include "Menu_utils.h"

enum class menuState {
	PLAY,
	LEADERBOARD,
	OPTIONS,
	EXIT
};

class Menu :
	public Menu_utils
{
protected:
	sf::Text t_play;
	sf::Text t_play2;
	sf::Text t_leaderboard;
	sf::Text t_leaderboard2;
	sf::Text t_options;
	sf::Text t_options2;
	sf::Text t_exit;
	sf::Text t_exit2;

	menuState menustate;

public:
	Menu();
	~Menu();
	
	menuState getstate();
	void setstate(menuState newstate);

	void draw(sf::RenderWindow* window);
};

#endif

