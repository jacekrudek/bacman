#pragma once
#ifndef GAME_H
#define GAME_H

#include "libraries.h"

#include "Menu.h"
#include "Options.h"
#include "Map.h"
#include "Pacman.h"
#include "Gameplay.h"

/**
	enum defining states which the whole program can be in
*/
enum class State
{
	MENU,
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

	Options options;
	Menu menu;
	//Map mapp;
	Gameplay ingame;

public:
	Game();
	~Game();

	const bool getWindow();

	void update();
	void render();
	void pollEvents();
	void pollMenuEvents();
	void pollOptionsEvents();
};


#endif // !GAME_H
