#include "Game.h"

void Game::initVar()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 1000;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Pacman 1.0", sf::Style::Titlebar | sf::Style::Close);
}

const bool Game::getWindow()
{
	return this->window->isOpen();
}

void Game::update()
{
	this->pollEvents();
}

void Game::render()
{
	this->window->clear();
	this->window->display();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
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