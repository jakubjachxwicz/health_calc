#pragma once

#include "API.h"

#include <iostream>
#include <map>
#include <any>
#include <fstream>

class EXPORT_API DataIO
{
public:
	void ExportToFile(std::map<std::string, std::any> dataContainer, const std::string& fileName);
};