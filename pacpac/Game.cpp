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

	this->ingame = new Gameplay;
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
		ingame->draw(window);
	}

	//get mouse position (temporary)
	/*sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
	std::cout << "Mouse Position: " << mousePosition.x << ", " << mousePosition.y << std::endl;*/
	
	//Display objects
	this->window->display();
}

/**
* @brief Event-polling method for in-game state
* 
* @details
* Calls pacman move function with correct argument list depending on input
* 
* @return Doesn't return anything
*/
void Game::pollEvents()
{
	bool moved = false;

	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
		{
			window->close();
		}
		if (this->event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				if (ingame->getGstate() == GPstate::PLAYING)
				{
					ingame->movepac(Direction::UP);
					moved = true;
				}
				else if (ingame->getGstate() == GPstate::WON)
				{
					switch (ingame->getPstate())
					{
					case PAUSEDstate::SAVE_SCORE:
						ingame->setPstate(PAUSEDstate::QUIT);
						break;
					case PAUSEDstate::QUIT:
						ingame->setPstate(PAUSEDstate::SAVE_SCORE);
						break;
					}
				}
				else if (ingame->getGstate() == GPstate::LOST)
				{
					switch (ingame->getPstate())
					{
					case PAUSEDstate::TRY_AGAIN:
						ingame->setPstate(PAUSEDstate::QUIT);
						break;
					case PAUSEDstate::QUIT:
						ingame->setPstate(PAUSEDstate::TRY_AGAIN);
						break;
					}
				}
				else if (ingame->getGstate() == GPstate::PAUSED)
				{
					switch (ingame->getPstate())
					{
					case PAUSEDstate::RESUME:
						ingame->setPstate(PAUSEDstate::QUIT);
						break;
					case PAUSEDstate::QUIT:
						ingame->setPstate(PAUSEDstate::RESUME);
						break;
					}
				}
				break;
			case sf::Keyboard::Down:	
				if (ingame->getGstate() == GPstate::PLAYING)
				{
					ingame->movepac(Direction::DOWN);
					moved = true;
				}
				else if (ingame->getGstate() == GPstate::WON)
				{
					switch (ingame->getPstate())
					{
					case PAUSEDstate::SAVE_SCORE:
						ingame->setPstate(PAUSEDstate::QUIT);
						break;
					case PAUSEDstate::QUIT:
						ingame->setPstate(PAUSEDstate::SAVE_SCORE);
						break;
					}
				}
				else if (ingame->getGstate() == GPstate::LOST)
				{
					switch (ingame->getPstate())
					{
					case PAUSEDstate::TRY_AGAIN:
						ingame->setPstate(PAUSEDstate::QUIT);
						break;
					case PAUSEDstate::QUIT:
						ingame->setPstate(PAUSEDstate::TRY_AGAIN);
						break;
					}
				}
				else if (ingame->getGstate() == GPstate::PAUSED)
				{
					switch (ingame->getPstate())
					{
					case PAUSEDstate::RESUME:
						ingame->setPstate(PAUSEDstate::QUIT);
						break;
					case PAUSEDstate::QUIT:
						ingame->setPstate(PAUSEDstate::RESUME);
						break;
					}
				}
				break;
			case sf::Keyboard::Left:	
				if (ingame->getGstate() == GPstate::PLAYING)
				{
					ingame->movepac(Direction::LEFT);
					moved = true;
				}
				break;
			case sf::Keyboard::Right:	
				if (ingame->getGstate() == GPstate::PLAYING)
				{
					ingame->movepac(Direction::RIGHT);
					moved = true;
				}
				break;
			case sf::Keyboard::Escape:
				if (ingame->getGstate() == GPstate::PLAYING)
				{
					ingame->setGstate(GPstate::PAUSED);
					ingame->setPstate(PAUSEDstate::RESUME);
				}
				break;
			case sf::Keyboard::Enter:
				if (ingame->getGstate() == GPstate::PAUSED)
				{
					switch (ingame->getPstate())
					{
					case PAUSEDstate::RESUME:
						ingame->setGstate(GPstate::PLAYING);
						break;
					case PAUSEDstate::QUIT:
						state = State::MENU;
						delete this->ingame;
						ingame = new Gameplay;
						break;
					}
				}
				else if (ingame->getGstate() == GPstate::LOST)
				{
					switch (ingame->getPstate())
					{
					case PAUSEDstate::TRY_AGAIN:
						delete this->ingame;
						ingame = new Gameplay;
						ingame->setGstate(GPstate::PLAYING);
						break;
					case PAUSEDstate::QUIT:
						state = State::MENU;
						delete this->ingame;
						ingame = new Gameplay;
						break;
					}
				}
				break;
			default:
				break;
			}
		}		
	}
	if (moved == false && ingame->getGstate() == GPstate::PLAYING)
	{
		ingame->movepac();
	}
	if (ingame->getGstate() == GPstate::PLAYING)
	{
		ingame->moveghost();
		ingame->checkcollision();
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