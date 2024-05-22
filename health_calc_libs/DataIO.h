#pragma once

#include "API.h"

#include <iostream>
#include <map>
#include <any>

class EXPORT_API DataIO
{
public:
	std::any a = 1;
	void ExportToFile(std::map<std::string, std::any> dataContainer, std::string fileName);
};