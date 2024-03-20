#pragma once
#ifndef OPTIONS_H
#define OPTIONS_H

#include "Menu.h"

enum class optionState {
	VOLUME,
	BACK
};

class Options : public Menu
{
protected:
	sf::Font font;
	sf::Text t_volume;
	sf::Text t_volume2;
	sf::Text t_back;
	sf::Text t_back2;


	optionState optionstate;

public:
	Options();
	~Options();
	
	void options_draw(sf::RenderWindow* window);
};

#endif

