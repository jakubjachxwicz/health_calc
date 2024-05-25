#pragma once

#include "API.h"

#include <string>


class EXPORT_API DataCourier
{
	std::wstring firstName;
	std::wstring lastName;
	int age;
	double weight;
	double height;
	bool isMale;
	double bmr;

public:
	DataCourier();

	std::wstring getFirstName();
	std::wstring getLastName();
	int getAge();
	double getWeight();
	double getHeight();
	bool getIsMale();
	double getBmr();

	void setFirstName(std::wstring fName);
	void setLastName(std::wstring lName);
	void setAge(int a);
	void setWeight(double w);
	void setHeight(double h);
	void setIsMale(bool im);
	void setBmr(double bmr);
};
