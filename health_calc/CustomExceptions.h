#pragma once
#include <iostream>


class AgeInputException : std::exception
{
public:
	const char* what()
	{
		return "Podano niepoprawny wiek";
	}
};

class HeightInputException : std::exception
{
public:
	const char* what()
	{
		return "Podano niepoprawny wzrost";
	}
};

class WeightInputException : std::exception
{
public:
	const char* what()
	{
		return "Podano niepoprawna mase";
	}
};

class AnyInputException : std::exception
{
public:
	const char* what()
	{
		return "Nie wszystkie wprowadzone dane sa poprawne";
	}
};

class UserInputException : std::exception
{
private:
	const char* message;

public:
	UserInputException(const char* msg) : message(msg) {}
	const char* what()
	{
		return message;
	}
};