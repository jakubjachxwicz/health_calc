#include "DataCourier.h"


DataCourier::DataCourier()
{
    firstName = "Michael";
    lastName = "Jordan";
    age = 61;
    height = 198;
    weight = 98;
    isMale = true;
    bmr = 3785.77;
}

std::string DataCourier::getFirstName()
{
    return firstName;
}

std::string DataCourier::getLastName()
{
    return lastName;
}

int DataCourier::getAge()
{
    return age;
}

double DataCourier::getWeight()
{
    return weight;
}

double DataCourier::getHeight()
{
    return height;
}

bool DataCourier::getIsMale()
{
    return isMale;
}

double DataCourier::getBmr()
{
    return bmr;
}

void DataCourier::setFirstName(std::string fName)
{
    firstName = fName;
}

void DataCourier::setLastName(std::string lName)
{
    lastName = lName;
}

void DataCourier::setAge(int a)
{
    age = a;
}

void DataCourier::setWeight(double w)
{
    weight = w;
}

void DataCourier::setHeight(double h)
{
    height = h;
}

void DataCourier::setIsMale(bool im)
{
    isMale = im;
}

void DataCourier::setBmr(double bmr)
{
    this->bmr = bmr;
}
