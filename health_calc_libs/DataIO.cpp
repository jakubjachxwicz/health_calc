#include "DataIO.h"


void DataIO::ExportToFile(std::map<std::string, std::any> dataContainer, const std::string& fileName)
{
	std::ofstream file(fileName);

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

void DataIO::SaveUserData(DataCourier& dataContainer)
{
	PWSTR path = nullptr;
	HRESULT hr = SHGetKnownFolderPath(FOLDERID_Documents, 0, NULL, &path);

	if (SUCCEEDED(hr)) {
		char charPath[MAX_PATH];
		size_t convertedChars = 0;
		wcstombs_s(&convertedChars, charPath, path, MAX_PATH);

		std::string filePath = charPath;
		filePath += "\\HealthCalc";

		CoTaskMemFree(path);

		std::filesystem::path new_dir = filePath;
		std::filesystem::create_directory(new_dir);

		std::wofstream output(filePath + "\\userdata");
		output.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));

		if (!output.is_open())
			throw std::ios_base::failure("Problem z otwarciem pliku");

		// First name
		// Last name
		// Age
		// Weight
		// Height
		// Is male
		output << dataContainer.getFirstName() << std::endl;
		output << dataContainer.getLastName() << std::endl;
		output << dataContainer.getAge() << std::endl;
		output << dataContainer.getWeight() << std::endl;
		output << dataContainer.getHeight() << std::endl;
		output << (dataContainer.getIsMale() ? "male" : "female") << std::endl;

		
		if (output.fail())
			throw std::ios_base::failure("Problem z zapisem do pliku");

		output.close();
		if (output.fail())
			throw std::ios_base::failure("Problem z zamknieciem pliku");
	}
}
