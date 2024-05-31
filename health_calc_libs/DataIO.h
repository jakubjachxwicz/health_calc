#pragma once
#pragma comment(lib, "shell32.lib")
#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING

#include "API.h"
#include "DataCourier.h"
#include "FileStructureException.h"

#include <iostream>
#include <map>
#include <any>
#include <fstream>
#include <codecvt>
#include <vector>
#include <windows.h>
#include <shlobj.h>
#include <filesystem>


class EXPORT_API DataIO
{
	std::string getDocumentsPath();

public:
	void exportToFile(std::map<std::string, std::any> dataContainer, const std::string& fileName);
	void saveUserData(DataCourier& dataContainer);
	DataCourier readUserData();
};