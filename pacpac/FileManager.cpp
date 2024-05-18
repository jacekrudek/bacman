#include "FileManager.h"

FileManager::FileManager()
{
	visuals = std::filesystem::current_path() / "Visuals";
	data = std::filesystem::current_path() / "Data";
}

std::filesystem::path FileManager::findfile(const std::string& name)
{
	//create regex to check file extensions
	std::regex expr("\\.\\w+");
	std::smatch m;

	//create main directory path
	std::filesystem::path mainpath;

	if (std::regex_search(name, m, expr))
	{
		if (m[0] == ".png" || m[0] == ".TTF")
		{
			mainpath = std::filesystem::current_path() / "Visuals";
		}
		else if (m[0] == ".txt")
		{
			mainpath = std::filesystem::current_path() / "Data";
		}
	}

	for (const auto& file : std::filesystem::directory_iterator(mainpath))
	{
		if (file.path().filename() == name)
		{
			return file.path();
		}
	}
}


