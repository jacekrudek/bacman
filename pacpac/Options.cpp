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

	setFonts(t_volume, "Volume", 500);
	setFonts(t_volume2, "Volume", 500);
	addOutline(t_volume2);
	t_volume.setPosition(270, 400);
	t_volume2.setPosition(270, 400);

	setFonts(t_back, "Back", 600);
	setFonts(t_back2, "Back", 600);
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

	//FILESYSTEM
	std::filesystem::path filepath(findfile("options.txt"));
	std::filesystem::path dirpath(filepath.parent_path());
	std::ifstream inputFile(filepath);
	std::ofstream tempFile(dirpath / "temp_options.txt");

	if (!tempFile)
	{
		std::cerr << "Cant override options file" << std::endl;
		return;
	}

	tempFile << "volume: ";
	tempFile << volume_level;

	inputFile.close();
	tempFile.close();

	std::filesystem::remove(filepath);

	std::filesystem::rename(dirpath / "temp_options.txt", filepath);

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

	//FILESYSTEM
	std::filesystem::path filepath(findfile("options.txt"));
	std::filesystem::path dirpath(filepath.parent_path());
	std::ifstream inputFile(filepath);
	std::ofstream tempFile(dirpath / "temp_options.txt");

	if (!tempFile)
	{
		std::cerr << "Cant override options file" << std::endl;
		return;
	}

	tempFile << "volume: ";
	tempFile << volume_level;

	inputFile.close();
	tempFile.close();

	std::filesystem::remove(filepath);

	std::filesystem::rename(dirpath / "temp_options.txt", filepath);

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
		//FILESYSTEM
		switch (volume_level)
		{
		case 0:
		{
			std::string file(findfile("volume0.png").string());
			if (!volume_texture.loadFromFile(file))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		}
		case 1:
		{
			std::string file(findfile("volume1.png").string());
			if (!volume_texture.loadFromFile(file))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		}
		case 2:
		{
			std::string file(findfile("volume2.png").string());
			if (!volume_texture.loadFromFile(file))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		}
		case 3:
		{
			std::string file(findfile("volume3.png").string());
			if (!volume_texture.loadFromFile(file))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		}
		case 4:
		{
			std::string file(findfile("volume4.png").string());
			if (!volume_texture.loadFromFile(file))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		}
		case 5:
		{
			std::string file(findfile("volume5.png").string());
			if (!volume_texture.loadFromFile(file))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		}
		case 6:
		{
			std::string file(findfile("volume6.png").string());
			if (!volume_texture.loadFromFile(file))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		}
		default:
			break;
		}
	}
	else if (optionstate == optionState::BACK)
	{
		switch (volume_level)
		{
		case 0:
		{
			std::string file(findfile("volume0.png").string());
			if (!volume_texture.loadFromFile(file))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		}
		case 1:
		{
			std::string file(findfile("volume11.png").string());
			if (!volume_texture.loadFromFile(file))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		}
		case 2:
		{
			std::string file(findfile("volume22.png").string());
			if (!volume_texture.loadFromFile(file))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		}
		case 3:
		{
			std::string file(findfile("volume33.png").string());
			if (!volume_texture.loadFromFile(file))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		}
		case 4:
		{
			std::string file(findfile("volume44.png").string());
			if (!volume_texture.loadFromFile(file))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		}
		case 5:
		{
			std::string file(findfile("volume55.png").string());
			if (!volume_texture.loadFromFile(file))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		}
		case 6:
		{
			std::string file(findfile("volume66.png").string());
			if (!volume_texture.loadFromFile(file))
			{
				std::cerr << "Failed to load volume texture" << std::endl;
			}
			else
			{
				this->volume_sprite.setTexture(volume_texture);
			}
			break;
		}
		default:
			break;
		}
	}

	sf::FloatRect volumeBounds = volume_sprite.getLocalBounds();
	volume_sprite.setOrigin(volumeBounds.width / 2.0f, volumeBounds.height / 2.0f);

	volume_sprite.setPosition(570, 400);
}

/**
* @brief Default Options class destructor
* 
*/
Options::~Options()
{

}


