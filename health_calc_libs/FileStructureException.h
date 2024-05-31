#pragma once

#include "API.h"
#include <exception>


class EXPORT_API FileStructureException : std::exception
{
public:
	const char* what();
};

