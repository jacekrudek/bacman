#pragma once
#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include "libraries.h"

#include "FileManager.h"

class Leaderboard
	:public FileManager
{
	std::vector<std::pair<std::string, double>> leaderboard;
	sf::Text l_text;
	sf::Text headline;

	sf::Font font;

public:
	Leaderboard();

	void draw(sf::RenderWindow* window);

	void update(const std::string& name, const double& time);

	double getbesttime();
};


#endif // !LEADERBOARD_H
