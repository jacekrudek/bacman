#include "Game.h"

/**
* @brief Initiates default Game class variables 
* 
* @details
* Helps keep everything more organized instead of sticking everything in constructor
* 
* @return Doesn't return anything
* 
*/
void Game::initVar()
{
	this->window = nullptr;

	this->state = State::MENU;
}

/**
* @brief Sets game window properties
* 
* @details
* Properties:
* - height
* - width
* - frame rate limit
* 
* @return Doesn't return anything
* 
*/
void Game::initWindow()
{
	this->videoMode.height = 1000;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Pacman 1.0", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(75);
}

/**
* @brief Checks if window is open
* 
* @return Returns YES if window is open, NO if not
* 
*/
const bool Game::getWindow()
{
	return this->window->isOpen();
}

/**
* @brief Main manager of game update and polling events
* 
* @details
* Updates game by calling certain event-polling functions
* 
* @return Doesn't return anything
* 
*/
void Game::update()
{
	if (state == State::MENU)
	{
		this->pollMenuEvents();
	}
	else if (state == State::OPTIONS)
	{
		this->pollOptionsEvents();
	}
	else
	{
		this->pollEvents();
	}
}

/**
* @brief Main manager of window objects rendering
* 
* @details
* Renders game elements by calling certain draw functions
* 
* @return Doesn't return anything
* 
*/
void Game::render()
{
	//Clear current frame
	this->window->clear();

	//Draw ingame objects depending on the games current state
	if (state == State::MENU)
	{
		menu.draw(window);
	}
	else if (state == State::OPTIONS)
	{
		options.draw(window);
	}
	else
	{

	}
	
	//Display objects
	this->window->display();
}

/**
* @brief Event-polling method for in-game state
* 
* @return Doesn't return anything
*/
void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
		{
			window->close();
		}
	}
}

/**
* @brief Event-polling method for menu state
* 
* @return Doesn't return anything
* 
*/
void Game::pollMenuEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
		{
			window->close();
		}		
		if (this->event.type == sf::Event::KeyPressed)
		{
			menuState* state_ptr;
			state_ptr = new menuState;
			
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				if (menu.getstate() == menuState::PLAY)
				{
					*state_ptr = menuState::EXIT;
					menu.setstate(state_ptr);
				}
				else if (menu.getstate() == menuState::OPTIONS)
				{
					*state_ptr = menuState::PLAY;
					menu.setstate(state_ptr);
				}
				else if (menu.getstate() == menuState::EXIT)
				{
					*state_ptr = menuState::OPTIONS;
					menu.setstate(state_ptr);
				}
				break;
			case sf::Keyboard::Down:
				if (menu.getstate() == menuState::PLAY)
				{
					*state_ptr = menuState::OPTIONS;
					menu.setstate(state_ptr);
				}
				else if (menu.getstate() == menuState::OPTIONS)
				{
					*state_ptr = menuState::EXIT;
					menu.setstate(state_ptr);
				}
				else if (menu.getstate() == menuState::EXIT)
				{
					*state_ptr = menuState::PLAY;
					menu.setstate(state_ptr);
				}
				break;
			case sf::Keyboard::Enter:
				if (menu.getstate() == menuState::PLAY)
				{
					this->state = State::INGAME;
				}
				else if (menu.getstate() == menuState::OPTIONS)
				{
					this->state = State::OPTIONS;
				}
				else if (menu.getstate() == menuState::EXIT)
				{
					window->close();
				}
				break;
			default:
				break;
			}
		}
	}
}

/**
* @brief Event-polling method for options state
* 
* @return Doesn't return anything
* 
*/
void Game::pollOptionsEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
		{
			window->close();
		}
		if (this->event.type == sf::Event::KeyPressed)
		{
			optionState* state_ptr;
			state_ptr = new optionState;

			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				if (options.getstate() == optionState::VOLUME)
				{
					*state_ptr = optionState::BACK;
					options.setstate(state_ptr);
				}
				else if (options.getstate() == optionState::BACK)
				{
					*state_ptr = optionState::VOLUME;
					options.setstate(state_ptr);
				}
				break;
			case sf::Keyboard::Down:
				if (options.getstate() == optionState::VOLUME)
				{
					*state_ptr = optionState::BACK;
					options.setstate(state_ptr);
				}
				else if (options.getstate() == optionState::BACK)
				{
					*state_ptr = optionState::VOLUME;
					options.setstate(state_ptr);
				}
				break;
			case sf::Keyboard::Enter:				
				if (options.getstate() == optionState::BACK)
				{
					this->state = State::MENU;
				}
				break;
			case sf::Keyboard::Left:
				if (options.getstate() == optionState::VOLUME)
				{
					options.lowervolume();
				}
				break;
			case sf::Keyboard::Right:
				if (options.getstate() == optionState::VOLUME)
				{
					options.topvolume();
				}
				break;
			default:
				break;
			}
		}
	}
}

/**
* @brief Game class constructor 
* 
* @details
* Initializes variables and window properties by calling certain functions
* 
*/
Game::Game()
{
	this->initVar();
	this->initWindow();	
}

/**
* @brief Default Game class destructor
* 
*/
Game::~Game()
{
	delete this->window;
}