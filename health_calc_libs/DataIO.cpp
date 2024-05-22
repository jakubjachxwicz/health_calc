#include "DataIO.h"


void DataIO::ExportToFile(std::map<std::string, std::any> dataContainer, const std::string& fileName)
{
	std::ofstream file(fileName + ".csv");

	if (!file.is_open())
		throw std::ios_base::failure("Problem z otwarciem pliku");

	for (auto& [key, val] : dataContainer)
	{
		file << key << ",";
		
		if (val.type() == typeid(int))
			file << std::any_cast<int>(val) << std::endl;
		else if (val.type() == typeid(std::string))
			file << std::any_cast<std::string>(val) << std::endl;
		else if (val.type() == typeid(const char*))
			file << std::any_cast<const char*>(val) << std::endl;
		else if (val.type() == typeid(double))
			file << std::any_cast<double>(val) << std::endl;
	}

	if (file.fail())
		throw std::ios_base::failure("Problem z zapisem do pliku");

	file.close();
	if (file.fail())
		throw std::ios_base::failure("Problem z zamknieciem pliku");
}
