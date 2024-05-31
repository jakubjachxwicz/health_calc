#include "FileStructureException.h"


const char* FileStructureException::what()
{
	return "Problem ze struktura danych w pliku";
}