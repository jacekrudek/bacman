#pragma once
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "libraries.h"

class FileManager
{
	std::filesystem::path visuals;
	std::filesystem::path data;

public:
	FileManager();
	std::filesystem::path findfile(const std::string& name);
};

#endif

