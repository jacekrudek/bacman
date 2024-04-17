#include "Options.h"


/**
* @brief Constructor for Options
*
* @details
* Sets default selected option when opening options window for the first time
* Sets properties of text to be later displayed using methods defined in Menu_utils class
*
*/
Options::Options()
{
	//default selected option set as volume
	optionstate = optionState::VOLUME;	

	setFonts(t_volume, "Volume", 300);
	setFonts(t_volume2, "Volume", 300);
	addOutline(t_volume2);
	t_volume.setPosition(270, 300);
	t_volume2.setPosition(270, 300);

	setFonts(t_back, "Back", 400);
	setFonts(t_back2, "Back", 400);
	addOutline(t_back2);	

	//set properties of volume sprite
	loadVolumeTexture();
}

/**
* @brief Draws all elements of the options screen inside the window
* 
* @details
* Changes current selected option depending on user input
* Loads correct volume texture
* 
*/
void Options::draw(sf::RenderWindow* window)
{
	window->draw(pacman_logo);

	loadVolumeTexture();

	switch (optionstate)
	{
	case optionState::VOLUME:
		window->draw(t_volume2);
		window->draw(volume_sprite);
		window->draw(t_back);		
		break;
	case optionState::BACK:
		window->draw(t_volume);
		window->draw(volume_sprite);
		window->draw(t_back2);
		break;
	default:
		break;
	}
}

/**
* @brief Options state getter
*
* @return Returns pointer to current options state
*
*/
optionState Options::getstate()
{
	return optionstate;
}

/**
* @brief Volume level getter
* 
* @return Returns current level of volume
* 
*/
int Options::getvolume()
{
	return volume_level;
}

/**
* @brief Lowers volume by 1 level
* 
*/
void Options::lowervolume()
{
	if (volume_level != 0)
	{
		volume_level--;
	}

	std::ifstream inputFile("options.txt");
	std::ofstream tempFile("temp.txt");

	if (!tempFile)
	{
		std::cerr << "Cant override options file" << std::endl;
		return;
	}

	tempFile << "volume: ";
	tempFile << volume_level;

	inputFile.close();
	tempFile.close();

	std::remove("options.txt");
	std::rename("temp.txt", "options.txt");

	return;
}

/**
* @brief Moves volume up by 1 level
* 
*/
void Options::topvolume()
{
	if (volume_level != 6)
	{
		volume_level++;
	}

	std::ifstream inputFile("options.txt");
	std::ofstream tempFile("temp.txt");

	if (!tempFile)
	{
		std::cerr << "Cant override options file" << std::endl;
		return;
	}

	tempFile << "volume: ";
	tempFile << volume_level;

	inputFile.close();
	tempFile.close();

	std::remove("options.txt");
	std::rename("temp.txt", "options.txt");

	return;
}

/**
* @brief Options state setter
*
* @param newstate Pointer to new options state
*
* @details
* Sets current state of the options screen
*
* @return Doesn't return anything
*
*/
void Options::setstate(optionState newstate)
{
	optionstate = newstate;

	return;
}

/**
* @brief Loads correct volume texture and sprite depending on the state
* 
* @details
* Manages the volume level indicator in case of selection and level
* 
* @return Doesn't return anything
* 
*/
void Options::loadVolumeTexture()
{
	if (optionstate == optionState::VOLUME)
	{
		switch (volume_level)
		{
		case 0:
			if (!volume_texture.loadFromFile("volume0.png"))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		case 1:
			if (!volume_texture.loadFromFile("volume1.png"))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		case 2:
			if (!volume_texture.loadFromFile("volume2.png"))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		case 3:
			if (!volume_texture.loadFromFile("volume3.png"))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		case 4:
			if (!volume_texture.loadFromFile("volume4.png"))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		case 5:
			if (!volume_texture.loadFromFile("volume5.png"))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		case 6:
			if (!volume_texture.loadFromFile("volume6.png"))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		default:
			break;
		}
	}
	else if (optionstate == optionState::BACK)
	{
		switch (volume_level)
		{
		case 0:
			if (!volume_texture.loadFromFile("volume0.png"))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		case 1:
			if (!volume_texture.loadFromFile("volume11.png"))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		case 2:
			if (!volume_texture.loadFromFile("volume22.png"))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		case 3:
			if (!volume_texture.loadFromFile("volume33.png"))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		case 4:
			if (!volume_texture.loadFromFile("volume44.png"))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		case 5:
			if (!volume_texture.loadFromFile("volume55.png"))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		case 6:
			if (!volume_texture.loadFromFile("volume66.png"))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		default:
			break;
		}
	}

	sf::FloatRect volumeBounds = volume_sprite.getLocalBounds();
	volume_sprite.setOrigin(volumeBounds.width / 2.0f, volumeBounds.height / 2.0f);

	volume_sprite.setPosition(570, 327);
}

/**
* @brief Default Options class destructor
* 
*/
Options::~Options()
{

}


