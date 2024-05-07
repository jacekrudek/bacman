#include "FileManager.h"

FileManager::FileManager()
{
	visuals = "E:\\GitHub\\bacman\\pacpac\\Visuals";
	data = "E:\\GitHub\\bacman\\pacpac\\Visuals";
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
			mainpath = "E:\\GitHub\\bacman\\pacpac\\Visuals";
		}
		else if (m[0] == ".txt")
		{
			mainpath = "E:\\GitHub\\bacman\\pacpac\\Data";
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


