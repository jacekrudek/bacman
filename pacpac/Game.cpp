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
	this->menu = new Menu;
	this->options = new Options;
	this->home_window = this->menu;

	this->state = State::MENU;

	if (!this->gamemusic.openFromFile("Data\\menumusic.wav"))
	{
		std::cout << "cant load music" << std::endl;
	}
	if (!this->menusound.openFromFile("Data\\menusound.wav"))
	{
		std::cout << "cant load menu sound effect" << std::endl;
	}
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
	else if (state == State::LEADERBOARD)
	{
		this->pollLeaderboardEvents();
	}
	else if (state == State::OPTIONS)
	{
		Options* options_ptr = dynamic_cast<Options*>(options);
		switch (options_ptr->getvolume())
		{
		case 0:
			this->menusound.setVolume(0);
			break;
		case 1:
			this->menusound.setVolume(16);
			break;
		case 2:
			this->menusound.setVolume(32);
			break;
		case 3:
			this->menusound.setVolume(48);
			break;
		case 4:
			this->menusound.setVolume(64);
			break;
		case 5:
			this->menusound.setVolume(80);
			break;
		case 6:
			this->menusound.setVolume(100);
			break;
		default:
			break;
		}
		this->pollOptionsEvents();
	}
	else
	{
		if (ingame->getGstate() != GPstate::PLAYING)
		{
			gamemusic.pause();
		}

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
	if (state == State::MENU || state == State::OPTIONS)
	{
		//POLIMORFIZM
		home_window->draw(window);
	}
	else if (state == State::LEADERBOARD)
	{
		leaderboard.draw(window);
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
					this->menusound.play();

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
					this->menusound.play();

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
					this->menusound.play();

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
					this->menusound.play();

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
					this->menusound.play();

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
					this->menusound.play();

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
					this->gamemusic.pause();

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
						this->gamemusic.play();
						ingame->setGstate(GPstate::PLAYING);
						break;
					case PAUSEDstate::QUIT:
						state = State::MENU;
						this->gamemusic.stop();
						delete this->ingame;
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
						this->gamemusic.stop();
						this->gamemusic.play();
						ingame->setGstate(GPstate::PLAYING);
						break;
					case PAUSEDstate::QUIT:
						state = State::MENU;
						this->gamemusic.stop();
						delete this->ingame;
						break;
					}
				}
				else if (ingame->getGstate() == GPstate::WON)
				{
					switch (ingame->getPstate())
					{
					case PAUSEDstate::SAVE_SCORE:
						ingame->setPstate(PAUSEDstate::SAVING);
						break;
					case PAUSEDstate::QUIT:
						state = State::MENU;
						this->gamemusic.stop();
						delete this->ingame;
						break;
					case PAUSEDstate::SAVING:
						ingame->updateleaderboard(leaderboard);
						state = State::MENU;
						delete this->ingame;
						break;
					}
				}
				break;
			default:
				break;
			}
		}	
		else if (event.type == sf::Event::TextEntered)
		{
			if (ingame->getPstate() == PAUSEDstate::SAVING)
			{
				if (event.text.unicode == '\b' && !ingame->get_input_text().empty())
				{
					std::string temp = ingame->get_input_text();
					temp.erase(temp.size() - 1);
					ingame->set_input_text(temp);
				}
				else if (event.text.unicode < 128 && event.text.unicode != '\r')
				{
					ingame->set_input_text(ingame->get_input_text() + static_cast<char>(event.text.unicode));
				}
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
	Menu* menu_ptr = dynamic_cast<Menu*>(menu);

	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
		{
			window->close();
		}		
		if (this->event.type == sf::Event::KeyPressed)
		{
			this->menusound.play();

			switch (event.key.code)
			{
			case sf::Keyboard::Up:				
				if (menu_ptr->getstate() == menuState::PLAY)
				{
					menu_ptr->setstate(menuState::EXIT);
				}
				else if (menu_ptr->getstate() == menuState::LEADERBOARD)
				{
					menu_ptr->setstate(menuState::PLAY);
				}
				else if (menu_ptr->getstate() == menuState::OPTIONS)
				{
					menu_ptr->setstate(menuState::LEADERBOARD);
				}
				else if (menu_ptr->getstate() == menuState::EXIT)
				{
					menu_ptr->setstate(menuState::OPTIONS);
				}
				break;
			case sf::Keyboard::Down:
				if (menu_ptr->getstate() == menuState::PLAY)
				{
					menu_ptr->setstate(menuState::LEADERBOARD);
				}
				else if (menu_ptr->getstate() == menuState::LEADERBOARD)
				{
					menu_ptr->setstate(menuState::OPTIONS);
				}
				else if (menu_ptr->getstate() == menuState::OPTIONS)
				{
					menu_ptr->setstate(menuState::EXIT);
				}
				else if (menu_ptr->getstate() == menuState::EXIT)
				{
					menu_ptr->setstate(menuState::PLAY);
				}
				break;
			case sf::Keyboard::Enter:
				if (menu_ptr->getstate() == menuState::PLAY)
				{
					this->ingame = new Gameplay;
					this->gamemusic.play();
					this->state = State::INGAME;
				}
				else if (menu_ptr->getstate() == menuState::LEADERBOARD)
				{
					this->state = State::LEADERBOARD;
				}
				else if (menu_ptr->getstate() == menuState::OPTIONS)
				{
					this->state = State::OPTIONS;
					this->home_window = options;
				}
				else if (menu_ptr->getstate() == menuState::EXIT)
				{
					window->close();
				}
				break;
			default:
				break;
			}
		}
	}
	menu = dynamic_cast<Menu_utils*>(menu_ptr);
}

/**
* @brief Event-polling method for options state
* 
* @return Doesn't return anything
* 
*/
void Game::pollOptionsEvents()
{
	Options* options_ptr = dynamic_cast<Options*>(options);

	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
		{
			window->close();
		}
		if (this->event.type == sf::Event::KeyPressed)
		{
			this->menusound.play();


			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				if (options_ptr->getstate() == optionState::VOLUME)
				{
					options_ptr->setstate(optionState::BACK);
				}
				else if (options_ptr->getstate() == optionState::BACK)
				{
					options_ptr->setstate(optionState::VOLUME);
				}
				break;
			case sf::Keyboard::Down:
				if (options_ptr->getstate() == optionState::VOLUME)
				{
					options_ptr->setstate(optionState::BACK);
				}
				else if (options_ptr->getstate() == optionState::BACK)
				{
					options_ptr->setstate(optionState::VOLUME);
				}
				break;
			case sf::Keyboard::Enter:				
				if (options_ptr->getstate() == optionState::BACK)
				{
					this->state = State::MENU;
					this->home_window = this->menu;
				}
				break;
			case sf::Keyboard::Left:
				if (options_ptr->getstate() == optionState::VOLUME)
				{
					options_ptr->lowervolume();
				}
				break;
			case sf::Keyboard::Right:
				if (options_ptr->getstate() == optionState::VOLUME)
				{
					options_ptr->topvolume();
				}
				break;
			case sf::Keyboard::Escape:
				this->state = State::MENU;
				this->home_window = this->menu;
				break;
			default:
				break;
			}
		}
	}
	options = dynamic_cast<Menu_utils*>(options_ptr);
}

void Game::pollLeaderboardEvents()
{
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
			case sf::Keyboard::Escape:
				this->state = State::MENU;
				this->home_window = this->menu;
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