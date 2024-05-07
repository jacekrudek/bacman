#pragma once
#ifndef OPTIONS_H
#define OPTIONS_H

#include "libraries.h"

#include "Menu_utils.h"
#include "FileManager.h"

enum class optionState {
	VOLUME,
	BACK
};

class Options 
	: public Menu_utils
{
protected:
	sf::Text t_volume;
	sf::Text t_volume2;
	sf::Text t_back;
	sf::Text t_back2;
	sf::Texture volume_texture;
	sf::Sprite volume_sprite;

	sf::FloatRect volumeBounds;

	optionState optionstate;
public:
	Options();
	~Options();

	optionState getstate();
	int getvolume();
	void lowervolume();
	void topvolume();
	void setstate(optionState newstate);
	void loadVolumeTexture();
	
	void draw(sf::RenderWindow* window);
};

#endif

