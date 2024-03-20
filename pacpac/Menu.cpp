#include "Menu.h"

/*
	-defining all of the options visible in main menu
	-setting all options as not chosen 
	-loading logo 
	-loading options
	-setting properties for all the displayed stuff
*/
Menu::Menu()
{	
	//default selected option set as PLAY
	this->menustate = menuState::PLAY;
	
	//load and set properties of logo
	logoSet();

	//load and set properties of font
	if (!font.loadFromFile("menufont.ttf")) 
	{		
		std::cerr << "Failed to load font" << std::endl;
	}

	//load and set properties of menu options
	setFonts(t_play, "Play", 300);
	setFonts(t_play2, "Play", 300);
	addOutline(t_play2);
	setFonts(t_options, "Options", 400);
	setFonts(t_options2, "Options", 400);
	addOutline(t_options2);
	setFonts(t_exit, "Exit", 500);
	setFonts(t_exit2, "Exit", 500);
	addOutline(t_exit2);
}

//defines all properties of main menu text
void Menu::setFonts(sf::Text& text, const std::string& input, const float& y)
{
	text.setFont(font);
	text.setString(input);
	text.setFillColor(sf::Color::Yellow);
	text.setCharacterSize(80);
	
	sf::FloatRect textBounds = text.getLocalBounds();
	text.setOrigin(textBounds.width / 2.0f, textBounds.height / 2.0f);
	text.setPosition(400, y);
}

void Menu::addOutline(sf::Text& text)
{
	text.setOutlineThickness(3.0f);
	text.setOutlineColor(sf::Color::Red);
}

//load and set properties of logo
void Menu::logoSet()
{	
	if (!logo_texture.loadFromFile("logo.png"))
	{
		std::cerr << "Failed to load logo" << std::endl;
	}
	else
	{
		this->pacman_logo.setTexture(logo_texture);
	}

	pacman_logo.setOrigin(logo_texture.getSize().x / 2.0f, logo_texture.getSize().y / 2.0f);

	pacman_logo.setPosition(400, 100);

	pacman_logo.setScale(0.8, 0.8);
}

void Menu::menu_draw(sf::RenderWindow* window)
{
	window->draw(pacman_logo);
	switch (this->menustate)
	{
	case menuState::PLAY:
		window->draw(t_play2);
		window->draw(t_options);
		window->draw(t_exit);
		break;
	case menuState::OPTIONS:
		window->draw(t_play);
		window->draw(t_options2);
		window->draw(t_exit);
		break;
	case menuState::EXIT:
		window->draw(t_play);
		window->draw(t_options);
		window->draw(t_exit2);
		break;
	}
}




Menu::~Menu()
{

}




