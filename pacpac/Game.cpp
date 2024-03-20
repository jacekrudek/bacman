#include "Game.h"

void Game::initVar()
{
	this->window = nullptr;

	this->state = State::MENU;
}

//Window properties
void Game::initWindow()
{
	this->videoMode.height = 1000;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Pacman 1.0", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(75);
}

//Check if window is open
const bool Game::getWindow()
{
	return this->window->isOpen();
}

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

void Game::render()
{
	//Clear current frame
	this->window->clear();

	//Draw ingame objects depending on the games current state
	if (state == State::MENU)
	{
		menu_draw(window);
	}
	else if (state == State::OPTIONS)
	{
		options_draw(window);
	}
	else
	{

	}
	
	//Display objects
	this->window->display();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{

	}
}

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
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				if (menustate == menuState::PLAY)
				{
					this->menustate = menuState::EXIT;
				}
				else if (menustate == menuState::OPTIONS)
				{
					this->menustate = menuState::PLAY;
				}
				else if (menustate == menuState::EXIT)
				{
					this->menustate = menuState::OPTIONS;
				}
				break;
			case sf::Keyboard::Down:
				if (menustate == menuState::PLAY)
				{
					this->menustate = menuState::OPTIONS;
				}
				else if (menustate == menuState::OPTIONS)
				{
					this->menustate = menuState::EXIT;
				}
				else if (menustate == menuState::EXIT)
				{
					this->menustate = menuState::PLAY;
				}
				break;
			case sf::Keyboard::Enter:
				if (menustate == menuState::PLAY)
				{
					this->state = State::INGAME;
				}
				else if (menustate == menuState::OPTIONS)
				{
					this->state = State::OPTIONS;
				}
				else if (menustate == menuState::EXIT)
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
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				if (optionstate == optionState::VOLUME)
				{
					this->optionstate = optionState::BACK;
				}
				else if (optionstate == optionState::BACK)
				{
					this->optionstate = optionState::VOLUME;
				}
				break;
			case sf::Keyboard::Down:
				if (optionstate == optionState::VOLUME)
				{
					this->optionstate = optionState::BACK;
				}
				else if (optionstate == optionState::BACK)
				{
					this->optionstate = optionState::VOLUME;
				}
				break;
			case sf::Keyboard::Enter:				
				if (optionstate == optionState::BACK)
				{
					this->state = State::MENU;
				}
				break;
			default:
				break;
			}
		}
	}
}

Game::Game()
{
	this->initVar();
	this->initWindow();	
}

Game::~Game()
{
	delete this->window;
}