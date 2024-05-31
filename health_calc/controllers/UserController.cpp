#include "UserController.h"
#include "DataIO.h"


void UserController::save()
{
	try
	{
		DataIO io;
		io.saveUserData(*courier);

		setInfoMessage("Zapisano dane u\u017Cytkownika w: Documents\\HealthCalc\\userdata");
	}
	catch (std::filesystem::filesystem_error& e)
	{
		setInfoMessage(e.what());
	}
	catch (std::ios_base::failure& e)
	{
		setInfoMessage(e.what());
	}
	catch (...)
	{
		setInfoMessage("Nie mo\u017Cna zapisa\u0107 do pliku");
	}
}

UserController::UserController(QObject* parent, DataCourier* dc)
{
	m_firstName = QString::fromStdWString(dc->getFirstName());
	m_lastName = QString::fromStdWString(dc->getLastName());
	m_age = dc->getAge();
	m_height = dc->getHeight();
	m_weight = dc->getWeight();
	m_isMale = dc->getIsMale();

	m_infoMessage = "";

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

QString UserController::getInfoMessage()
{
	return m_infoMessage;
}

void UserController::setLastName(QString lName)
{
	if (m_lastName == lName)
		return;

	m_lastName = lName;
	courier->setLastName(m_lastName.toStdWString());
	emit lastNameChanged(m_firstName);
}

void UserController::setAge(int a)
{
	if (m_age == a)
		return;

	m_age = a;
	courier->setAge(m_age);
	emit ageChanged(m_age);
}

void UserController::setWeight(double w)
{
	if (m_weight == w)
		return;

	m_weight = w;
	courier->setWeight(m_weight);
	emit weightChanged(m_weight);
}

void UserController::setHeight(double h)
{
	if (m_height == h)
		return;

	m_height = h;
	courier->setHeight(m_height);
	emit heightChanged(m_height);
}

void UserController::setIsMale(bool ismale)
{
	if (m_isMale == ismale)
		return;

	m_isMale = ismale;
	courier->setIsMale(m_isMale);
	emit isMaleChanged(m_isMale);
}

void UserController::setInfoMessage(QString ms)
{
	if (m_infoMessage == ms)
		return;

	m_infoMessage = ms;
	emit infoMessageChanged(m_infoMessage);
}

void UserController::setFirstName(QString fName)
{
	if (m_firstName == fName)
		return;

	m_firstName = fName;
	courier->setFirstName(m_firstName.toStdWString());
	emit firstNameChanged(m_firstName);
}