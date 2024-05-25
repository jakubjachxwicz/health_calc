#pragma once
#pragma comment(lib, "shell32.lib")

#include "API.h"
#include "DataCourier.h"

#include <iostream>
#include <map>
#include <any>
#include <fstream>
#include <vector>
#include <windows.h>
#include <shlobj.h>


class EXPORT_API DataIO
{
public:
	void ExportToFile(std::map<std::string, std::any> dataContainer, const std::string& fileName);
	void SaveUserData(DataCourier& dataContainer);
};