#pragma once
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <string>

//sfml libraries
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum class menuState {
	PLAY,
	OPTIONS,
	EXIT
};

class Menu
{
protected:
	sf::Texture logo_texture;
	sf::Sprite pacman_logo;
	sf::Font font;
	sf::Text t_play;
	sf::Text t_play2;
	sf::Text t_options;
	sf::Text t_options2;
	sf::Text t_exit;
	sf::Text t_exit2;

	menuState menustate;

public:
	Menu();
	~Menu();

	void setFonts(sf::Text& text, const std::string& input, const float& y);
	void addOutline(sf::Text& text);
	void logoSet();

	void menu_draw(sf::RenderWindow* window);
};

#endif

