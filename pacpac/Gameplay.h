#pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "libraries.h"

#include "Map.h"
#include "Pacman.h"
#include "Movement.h"
#include "Particles.h"
#include "Ghost.h"
#include "FileManager.h"
#include "Leaderboard.h"

/**
* @brief Main class for managing gameplay
* 
* @param Map class including map image
* @param Pacman class including pacman image and pacman-related variables
* @param Movement class that manages pacman and ghosts movement
* 
*/

enum class GPstate
{
	PLAYING,
	WON,
	LOST,
	PAUSED
};

enum class PAUSEDstate
{
	SAVE_SCORE,
	SAVING,
	RESUME,
	TRY_AGAIN,
	QUIT
};


class Gameplay
{
	Map map;
	Pacman pacman;
	Movement movement;
	Particles particles;
	Ghost ghost_1;
	Ghost ghost_2;
	Ghost ghost_3;
	Ghost ghost_4;
	GPstate Gstate;
	PAUSEDstate Pstate;
	//Leaderboard leaderboard;

	sf::Texture pause_shade_texture;
	sf::Sprite pause_shade_sprite;
	sf::Texture pause_menu_texture;
	sf::Sprite pause_menu_sprite;
	sf::Font font;
	sf::Text y_won;
	sf::Text y_lost;
	sf::Text paused;
	sf::Text resume;
	sf::Text resume2;
	sf::Text quit;
	sf::Text quit2;
	sf::Text try_again;
	sf::Text try_again2;
	sf::Text save_score;
	sf::Text save_score2;
	sf::Text time_text;
	sf::Text highscore;
	sf::Text inputname;
	sf::Text nickname;

	sf::Clock clock;
	sf::Time time;
	sf::Time pausedtime;

	std::string input_text; //for leaderboard name

	bool pausedtimer;
public:
	Gameplay();

	void movepac(const Direction& dirr);
	void movepac();

	void moveghost();

	void checkcollision();

	GPstate getGstate();

	PAUSEDstate getPstate();

	void setPstate(const PAUSEDstate& pstate);

	void setGstate(const GPstate& gstate);

	void draw(sf::RenderTarget* window);

	void setFonts(sf::Text& text, const std::string& input, const float& y, const int& charsize);

	void setAllText();

	void addOutline(sf::Text& text, const sf::Color& color);

	void updateleaderboard(Leaderboard& leaderboard);

	std::string get_input_text();

	void set_input_text(const std::string& input);
};

#endif

