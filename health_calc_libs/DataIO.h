#pragma once

#include "API.h"

#include <iostream>
#include <map>
#include <any>
#include <fstream>
#include <vector>


class EXPORT_API DataIO
{
public:
	void ExportToFile(std::map<std::string, std::any> dataContainer, const std::string& fileName);
	void SaveUserData(std::vector<std::any> dataContainer);
};