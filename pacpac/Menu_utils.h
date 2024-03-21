#pragma once
#ifndef MENUUTILS_H
#define MENUUTILS_H

#include "libraries.h"

class Menu_utils
{
protected:
	sf::Texture logo_texture;
	sf::Sprite pacman_logo;
	sf::Font font;

	int volume_level;
public:
	Menu_utils();
	~Menu_utils();

	virtual void draw(sf::RenderWindow* window) = 0;

	void setFonts(sf::Text& text, const std::string& input, const float& y);
	void addOutline(sf::Text& text);
	void logoSet();	

	void read_options();
	void set_default();
};

#endif

