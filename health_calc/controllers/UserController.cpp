#include "UserController.h"
#include "DataIO.h"


void UserController::save()
{
	DataIO io;
	io.SaveUserData(*courier);
}

UserController::UserController(QObject* parent, DataCourier* dc)
{
	m_firstName = QString::fromStdWString(dc->getFirstName());
	m_lastName = QString::fromStdWString(dc->getLastName());
	m_age = dc->getAge();
	m_height = dc->getHeight();
	m_weight = dc->getWeight();
	m_isMale = dc->getIsMale();

	courier = dc;
}

QString UserController::getFirstName()
{
	return m_firstName;
}

QString UserController::getLastName()
{
	return m_lastName;
}

int UserController::getAge()
{
	return m_age;
}

double UserController::getWeight()
{
	return m_weight;
}

double UserController::getHeight()
{
	return m_height;
}

bool UserController::getIsMale()
{
	return m_isMale;
}

void UserController::setLastName(QString lName)
{
	if (m_lastName == lName)
		return;

	m_lastName = lName;
	emit lastNameChanged(m_firstName);
}

void UserController::setAge(int a)
{
	if (m_age == a)
		return;

	m_age = a;
	emit ageChanged(m_age);
}

void UserController::setWeight(double w)
{
	if (m_weight == w)
		return;

	m_weight = w;
	emit weightChanged(m_weight);
}

void UserController::setHeight(double h)
{
	if (m_height == h)
		return;

	m_height = h;
	emit heightChanged(m_height);
}

void UserController::setIsMale(bool ismale)
{
	if (m_isMale == ismale)
		return;

	m_isMale = ismale;
	emit isMaleChanged(m_isMale);
}

void UserController::setFirstName(QString fName)
{
	if (m_firstName == fName)
		return;

	m_firstName = fName;
	emit firstNameChanged(m_firstName);
}