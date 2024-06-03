#pragma once
#ifndef GAME_H
#define GAME_H

#include "libraries.h"

#include "Menu.h"
#include "Options.h"
#include "Menu_utils.h"
#include "Map.h"
#include "Pacman.h"
#include "Gameplay.h"
#include "Leaderboard.h"

/**
	enum defining states which the whole program can be in
*/
enum class State
{
	MENU,
	LEADERBOARD,
	OPTIONS,
	INGAME
};


class Game 
{
	//the game window
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videoMode;

	State state;
	void initVar();
	void initWindow();

	Menu_utils* options;
	Menu_utils* menu;
	Menu_utils* home_window;
	Gameplay* ingame;
	Leaderboard leaderboard;

	std::string input_text;

	sf::Music gamemusic;
	sf::Music menusound;
public:
	Game();
	~Game();

	const bool getWindow();

	void update();
	void render();
	void pollEvents();
	void pollMenuEvents();
	void pollOptionsEvents();
	void pollLeaderboardEvents();
};


#endif // !GAME_H
