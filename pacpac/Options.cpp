#include "Options.h"

Options::Options()
{
	//default selected option set as volume
	this->optionstate = optionState::VOLUME;

	//load and set properties of logo
	logoSet();

	//load and set properties of font
	if (!font.loadFromFile("menufont.ttf"))
	{
		std::cerr << "Failed to load font" << std::endl;
	}

	setFonts(t_volume, "Volume", 300);
	setFonts(t_volume2, "Volume", 300);
	addOutline(t_volume2);
	setFonts(t_back, "Back", 400);
	setFonts(t_back2, "Back", 400);
	addOutline(t_back2);
}

void Options::options_draw(sf::RenderWindow* window)
{
	window->draw(pacman_logo);
	switch (this->optionstate)
	{
	case optionState::VOLUME:
		window->draw(t_volume2);
		window->draw(t_back);
		break;
	case optionState::BACK:
		window->draw(t_volume);
		window->draw(t_back2);
		break;
	default:
		break;
	}
}

Options::~Options()
{

}


