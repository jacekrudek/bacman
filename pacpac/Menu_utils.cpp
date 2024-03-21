#include "Menu_utils.h"

/**
* @breif Menu_utils class constructor
* 
* @details
* Sets properties of the Pacman logo to be displayed correctly
* Loads desired menu text font
* Loads last set options
* 
*/
Menu_utils::Menu_utils()
{
	//setting properties of logo
	logoSet();

	//load font
	if (!font.loadFromFile("menufont.ttf"))
	{
		std::cerr << "Failed to load font" << std::endl;
	}

	//get last set options
	read_options();
}

/**
* @breif Default Menu_utils class destructor
* 
*/
Menu_utils::~Menu_utils()
{

}

/**
* @breif Sets properties of text to be later displayed
* 
* @param text Text variable which is getting it's settings changed
* @param input String containing text to be assigned to the text variable and later displayed
* @param y Height on which the text will be displayed
* 
* @return Doesn't return anything
* 
*/
void Menu_utils::setFonts(sf::Text& text, const std::string& input, const float& y)
{
	text.setFont(font);
	text.setString(input);
	text.setFillColor(sf::Color::Yellow);
	text.setCharacterSize(80);

	sf::FloatRect textBounds = text.getLocalBounds();
	text.setOrigin(textBounds.width / 2.0f, textBounds.height / 2.0f);
	text.setPosition(400, y);
}

/**
* @brief Adds red outline to text
* 
* @param text Text which is getting the outline added
* 
* @details
* This method purpose is to show which option is currently selected in menu
* 
* @return Doesnt return anything
* 
*/
void Menu_utils::addOutline(sf::Text& text)
{
	text.setOutlineThickness(3.0f);
	text.setOutlineColor(sf::Color::Red);
}

/**
* @brief Sets properties of logo displayed on top of the menu
* 
* @return Doesn't return anything
* 
*/
void Menu_utils::logoSet()
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

/**
* @brief Reads and sets last set options got from options.txt file
* 
* @details
* Parcing in the options file is important, space only in front of the setting value
* 
* @return Doesn't return anything
* 
*/
void Menu_utils::read_options()
{
	std::ifstream inputfile("options.txt");

	if (!inputfile)
	{
		std::cerr << "Can't open the options file, setting default settings" << std::endl;
		set_default();
		return;
	}

	std::string line;	
	while (std::getline(inputfile, line))
	{
		std::istringstream iss(line);

		std::string buffer;
		std::string value;
		iss >> buffer;
		iss >> value;

		if (buffer == "volume:")
		{
			try
			{
				volume_level = std::stoi(value);
			}
			catch (const std::invalid_argument& e)
			{
				std::cerr << "Error: Can't load latest set volume. Word '" << value << "' is not a valid integer." << std::endl;
				set_default();
			}
		}
	}
	return;
}
/**
* @brief Sets default settings of the game
* 
* @return Doesn't return anything
* 
*/
void Menu_utils::set_default()
{
	volume_level = 3;
	set_default();

	return;
}
