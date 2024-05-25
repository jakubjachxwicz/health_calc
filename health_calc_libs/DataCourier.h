#pragma once

#include "API.h"

#include <string>


class EXPORT_API DataCourier
{
	std::string firstName;
	std::string lastName;
	int age;
	double weight;
	double height;
	bool isMale;
	double bmr;

public:
	DataCourier();

	std::string getFirstName();
	std::string getLastName();
	int getAge();
	double getWeight();
	double getHeight();
	bool getIsMale();
	double getBmr();

	void setFirstName(std::string fName);
	void setLastName(std::string lName);
	void setAge(int a);
	void setWeight(double w);
	void setHeight(double h);
	void setIsMale(bool im);
	void setBmr(double bmr);
};
