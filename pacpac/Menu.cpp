#include "Menu.h"

/**
* @brief Constructor for Menu
*
* @details
* Sets default selected menu option on game launch (play)
* Sets properties of all text displayed in menu using other methods
*
*/
Menu::Menu()
{
	//default selected option set as PLAY
	menustate = new menuState;
	*menustate = menuState::PLAY;

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

/**
* @brief Draws all objects in program window
* 
* @param window Pointer to game window
* 
* @details
* Stuff drawn depends on current menu state
* 
*/
void Menu::draw(sf::RenderWindow* window)
{
	window->draw(pacman_logo);
	switch (*menustate)
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

	return;
}

/**
* @brief Menu state getter
* 
* @return Returns pointer to current menu state
* 
*/
menuState Menu::getstate()
{
	return *menustate;
}

/**
* @brief Menu state setter
* 
* @param newstate Pointer to new menu state
* 
* @details
* Sets current state of main menu
* 
* @return Doesn't return anything
* 
*/
void Menu::setstate(menuState* newstate)
{
	if (menustate != nullptr)
	{
		delete menustate;
	}
	menustate = newstate;

	return;
}

/**
* @brief Default class destroyer
* 
*/
Menu::~Menu()
{

}






