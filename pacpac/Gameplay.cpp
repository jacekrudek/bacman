#include "Gameplay.h"

Gameplay::Gameplay() : ghost_1(1), ghost_2(2), ghost_3(3), ghost_4(4), Gstate(GPstate::PLAYING),
Pstate(PAUSEDstate::QUIT) 
{
	sf::Image background;
	const sf::Color bg_color = sf::Color(0, 0, 0, 150);
	background.create(800, 1000, bg_color);

	bool pausedtimer = false;
	pausedtime = sf::Time::Zero;
	clock.restart();

	pause_shade_texture.loadFromImage(background);
	pause_shade_sprite.setTexture(pause_shade_texture);
	
	pause_menu_texture.loadFromFile("Visuals\\pausemenu.png");
	this->pause_menu_sprite.setTexture(pause_menu_texture);

	font.loadFromFile("Visuals\\menufont.TTF");
	setFonts(y_won, "YOU WIN", 330, 60);
	addOutline(y_won, bg_color);
	setFonts(nickname, "NICKNAME", 330, 60);
	addOutline(nickname, bg_color);
	setFonts(y_lost, "YOU LOSE", 330, 60);
	addOutline(y_lost, bg_color);
	setFonts(paused, "PAUSED", 325, 70);
	addOutline(paused, bg_color);
	setFonts(resume, "RESUME", 450.f, 50);
	setFonts(resume2, "RESUME", 450.f, 50);
	addOutline(resume2, sf::Color::Red);
	setFonts(try_again, "TRY AGAIN", 450, 50);
	setFonts(try_again2, "TRY AGAIN", 450, 50);	
	addOutline(try_again2, sf::Color::Red);
	setFonts(save_score, "SAVE SCORE", 450, 50);
	setFonts(save_score2, "SAVE SCORE", 450, 50);
	addOutline(save_score2, sf::Color::Red);
	setFonts(quit, "QUIT", 520.f, 50);
	setFonts(quit2, "QUIT", 520.f, 50);
	addOutline(quit2, sf::Color::Red);
	setFonts(time_text, "QUIT", 50.f, 40);
	time_text.setPosition(100, 50);

	std::ifstream infile("Data\\leaderboard.txt");
	std::string line;
	double besttime;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		std::string name;
		double time;
		iss >> name >> besttime;
		break;
	}
	
	std::ostringstream oss;

	oss << std::right << "HIGHSCORE\n" << std::fixed << std::setprecision(3) << besttime;

	setFonts(highscore, oss.str(), 50.f, 40);
	highscore.setPosition(570, 73);

	setFonts(inputname, "", 330, 50);
	inputname.setPosition(200, 450);
};


/**
* @brief Function calling pacman-moving function in Movement class if there is any user input movement-related
*/
void Gameplay::movepac(const Direction& dirr)
{
	for (int i = 0; i < 2; i++)
	{
		movement.movepac(pacman, dirr);
		particles.updateparticles(pacman);
	}
}

/**
* @brief Function calling pacman-moving function in Movement class if there is no user input movement-related
*/
void Gameplay::movepac()
{
	for (int i = 0; i < 2; i++)
	{
		movement.movepac(pacman, pacman.getdir());
		particles.updateparticles(pacman);
		if (particles.eaten())
		{
			Gstate = GPstate::WON;
		}
	}
}

void Gameplay::moveghost()
{
	for (int i = 0; i < 2; i++)
	{
		movement.moveghost(ghost_1);
		movement.moveghost(ghost_2);
		movement.moveghost(ghost_3);
		movement.moveghost(ghost_4);
	}
}

/**
* @brief Function managing rendering when in-game
*/
void Gameplay::draw(sf::RenderTarget* window)
{
	map.draw(window);	
	particles.draw(window);
	pacman.draw(window);
	ghost_1.draw(window);
	ghost_2.draw(window);
	ghost_3.draw(window);
	ghost_4.draw(window);
	window->draw(time_text);
	window->draw(highscore);

	if (Gstate == GPstate::WON)
	{		
		pausedtime = time;
		window->draw(pause_shade_sprite);
		window->draw(pause_menu_sprite);		
		switch (Pstate)
		{
		case PAUSEDstate::SAVE_SCORE:
			window->draw(y_won);
			window->draw(save_score2);
			window->draw(quit);
			break;
		case PAUSEDstate::QUIT:
			window->draw(y_won);
			window->draw(save_score);
			window->draw(quit2);
			break;
		case PAUSEDstate::SAVING: 
			window->draw(nickname);
			inputname.setString(input_text);
			window->draw(inputname);
			break;
		}
	}
	else if (Gstate == GPstate::LOST)
	{
		window->draw(pause_shade_sprite);
		window->draw(pause_menu_sprite);
		window->draw(y_lost);
		switch (Pstate)
		{
		case PAUSEDstate::TRY_AGAIN:
			window->draw(try_again2);
			window->draw(quit);
			break;
		case PAUSEDstate::QUIT:
			window->draw(try_again);
			window->draw(quit2);
			break;
		}
	}
	else if (Gstate == GPstate::PAUSED)
	{
		if (pausedtimer == false)
		{
			pausedtime = time;
			pausedtimer = true;
		}		
		window->draw(pause_shade_sprite);
		window->draw(pause_menu_sprite);
		window->draw(paused);
		switch (Pstate)
		{
		case PAUSEDstate::RESUME:
			window->draw(resume2);
			window->draw(quit);
			break;
		case PAUSEDstate::QUIT:
			window->draw(resume);
			window->draw(quit2);
			break;
		}
	}
	else
	{
		if (pausedtimer == true)
		{
			clock.restart();
			pausedtimer = false;
		}
		time = pausedtime + clock.getElapsedTime();

		//time update	
		std::stringstream ss;
		ss << std::fixed << std::setprecision(3) << time.asSeconds();
		std::string timestring("TIME\n" + ss.str());
		time_text.setString(timestring);
	}

	//movement.draw(window);
}

void Gameplay::checkcollision()
{
	if (movement.colision(pacman, ghost_1) == true || movement.colision(pacman, ghost_2) == true ||
		movement.colision(pacman, ghost_3) == true || movement.colision(pacman, ghost_4) == true)
	{
		Gstate = GPstate::LOST;
		Pstate = PAUSEDstate::TRY_AGAIN;
	}
}

void Gameplay::setFonts(sf::Text& text, const std::string& input, const float& y, const int& charsize)
{
	text.setFont(font);
	text.setString(input);
	text.setFillColor(sf::Color::Yellow);
	text.setCharacterSize(charsize);

	sf::FloatRect textBounds = text.getLocalBounds();
	text.setOrigin(textBounds.width / 2.0f, textBounds.height / 2.0f);
	text.setPosition(400, y);
}


void Gameplay::addOutline(sf::Text& text, const sf::Color& color)
{
	text.setOutlineThickness(3.0f);
	text.setOutlineColor(color);
}

void Gameplay::updateleaderboard(Leaderboard& leaderboard)
{
	leaderboard.update(input_text, pausedtime.asSeconds());
}

std::string Gameplay::get_input_text()
{
	return input_text;
}

void Gameplay::set_input_text(const std::string& input)
{
	input_text = input;
}

PAUSEDstate Gameplay::getPstate()
{
	return Pstate;
}

void Gameplay::setGstate(const GPstate& gstate)
{
	Gstate = gstate;
}

void Gameplay::setPstate(const PAUSEDstate& pstate)
{
	Pstate = pstate;
}

GPstate Gameplay::getGstate()
{
	return Gstate;
}

