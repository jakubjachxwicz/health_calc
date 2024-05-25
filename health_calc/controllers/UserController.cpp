#include "UserController.h"

UserController::UserController(QObject* parent)
{
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
	return m_height;
}

double UserController::getHeight()
{
	return m_height;
}

bool UserController::getIsMale()
{
	return m_isMale;
}

double UserController::getBmr()
{
	return m_bmr;
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

void UserController::setBmr(double bmr)
{
	if (m_bmr == bmr)
		return;

	m_bmr = bmr;
	emit bmrChanged(m_bmr);
}


void UserController::setFirstName(QString fName)
{
	if (m_firstName == fName)
		return;

	m_firstName = fName;
	emit firstNameChanged(m_firstName);
}