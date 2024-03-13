#pragma once
#ifndef GAME_H
#define GAME_H

//sfml libraries
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videoMode;

	void initVar();
	void initWindow();

public:
	Game();
	~Game();

	const bool getWindow();

	void update();
	void render();
	void pollEvents();
};


#endif // !GAME_H
