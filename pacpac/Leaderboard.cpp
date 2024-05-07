#include "Leaderboard.h"

Leaderboard::Leaderboard()
{
	std::filesystem::path filepath(findfile("leaderboard.txt"));
	std::filesystem::path dirpath(filepath.parent_path());
	std::ifstream inputFile(filepath);

	std::string line;
	int it = 0;
	while (std::getline(inputFile, line))
	{
		std::istringstream iss(line);
		std::string name;
		double time;
		if (iss >> name >> time)
		{
			leaderboard.push_back(std::make_pair(name, time));
		}
		it++;
	}

	std::filesystem::path fontpath(findfile("menufont.TTF"));
	font.loadFromFile(fontpath.string());

	l_text.setFont(font);
	l_text.setFillColor(sf::Color::Yellow);
	l_text.setPosition(20, 200);
	l_text.setCharacterSize(30);
	l_text.setLineSpacing(2);

	headline.setFont(font);
	headline.setString("LEADERBOARD");
	headline.setFillColor(sf::Color::Yellow);
	headline.setCharacterSize(65);
	headline.setOutlineThickness(3.0f);
	headline.setOutlineColor(sf::Color::Red);
	sf::FloatRect headBounds = headline.getLocalBounds();
	headline.setOrigin(headBounds.width / 2.0f, headBounds.height / 2.0f);
	headline.setPosition(400, 50);
}

void Leaderboard::draw(sf::RenderWindow* window)
{
	window->draw(headline);

	std::ostringstream oss;

	for (size_t i = 0; i < leaderboard.size(); ++i) {
		oss << std::right << std::setw(4) << i+1 << ". " << std::left << std::setw(10) << leaderboard[i].first << std::right << std::fixed << std::setprecision(3) << leaderboard[i].second << std::endl;
	}
	l_text.setString(oss.str());
	window->draw(l_text);
}

void Leaderboard::update(const std::string& name, const double& time)
{/*
	std::vector<std::pair<std::string, double>> leaderboard;*/

	std::filesystem::path filepath(findfile("leaderboard.txt"));
	std::filesystem::path dirpath(filepath.parent_path());
	//std::ifstream inputFile(filepath);

	//std::string line;
	//int it = 0;
	//while (std::getline(inputFile, line))
	//{
	//	std::istringstream iss(line);
	//	
	//	iss >> leaderboard[it].first >> leaderboard[it].second;
	//	it++;
	//}
	if (time < leaderboard.back().second)
	{
		leaderboard.push_back({ name, time });

		//RANGES
		auto comparator = [](const auto& lhs, const auto& rhs) {
			return lhs.second < rhs.second;
			};
		std::ranges::sort(leaderboard, comparator);

		leaderboard.erase(leaderboard.end() - 1);
	}

	std::ofstream tempFile(dirpath / "temp_leaderboard.txt");

	if (!tempFile)
	{
		std::cerr << "Cant override leaderboard file" << std::endl;
		return;
	}

	for (const auto& pair : leaderboard)
	{
		tempFile << pair.first << " " << std::fixed << std::setprecision(3) << pair.second << std::endl;
	}

	//inputFile.close();
	tempFile.close();

	std::filesystem::remove(filepath);

	std::filesystem::rename(dirpath / "temp_leaderboard.txt", filepath);
}

double Leaderboard::getbesttime()
{
	return leaderboard[0].second;
}
