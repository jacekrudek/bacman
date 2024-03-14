#pragma once
#ifndef GAME_H
#define GAME_H

//sfml libraries
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Menu.h"

/**
	enum defining states which the whole program can be in
*/
enum class State
{
	MENU,
	OPTIONS,
	INGAME
};

class Game : public Menu
{
	//the game window
	sf::RenderWindow* window;
	//
	sf::Event event;
	sf::VideoMode videoMode;

	State state;
	void initVar();
	void initWindow();

public:
	Game();
	~Game();

	const bool getWindow();

	void update();
	void render();
	void pollEvents();
	void pollMenuEvents();
};


#endif // !GAME_H
