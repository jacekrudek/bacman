#include "Gameplay.h"

Gameplay::Gameplay() : ghost_1(1), ghost_2(2), ghost_3(3), ghost_4(4), Gstate(GPstate::PLAYING),
Pstate(PAUSEDstate::RESUME) 
{
	sf::Image background;
	const sf::Color bg_color = sf::Color(0, 0, 0, 150);
	background.create(800, 1000, bg_color);

	pause_shade_texture.loadFromImage(background);
	pause_shade_sprite.setTexture(pause_shade_texture);
	
	pause_menu_texture.loadFromFile("pausemenu.png");
	this->pause_menu_sprite.setTexture(pause_menu_texture);

	font.loadFromFile("menufont.ttf");
	setFonts(y_won, "YOU  WIN", 285.f, 120);
	addOutline(y_won, bg_color);
	setFonts(y_lost, "YOU  LOSE", 285.f, 120);
	addOutline(y_lost, bg_color);
	setFonts(paused, "PAUSED", 285.f, 120);
	addOutline(paused, bg_color);
	setFonts(resume, "RESUME", 400.f, 80);
	setFonts(resume2, "RESUME", 400.f, 80);
	addOutline(resume2, sf::Color::Red);
	setFonts(try_again, "TRY  AGAIN", 400.f, 80);
	setFonts(try_again2, "TRY  AGAIN", 400.f, 80);
	addOutline(try_again2, sf::Color::Red);
	setFonts(quit, "QUIT", 470.f, 80);
	setFonts(quit2, "QUIT", 470.f, 80);
	addOutline(quit2, sf::Color::Red);
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

	if (Gstate == GPstate::WON)
	{
		window->draw(pause_shade_sprite);
		window->draw(pause_menu_sprite);
		window->draw(y_won);
		switch (Pstate)
		{
		case PAUSEDstate::SAVE_SCORE:
			window->draw(try_again2);
			window->draw(quit);
			break;
		case PAUSEDstate::QUIT:
			window->draw(try_again);
			window->draw(quit);
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

