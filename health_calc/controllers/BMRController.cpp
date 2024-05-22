#include "BMRController.h"
#include "BMRExceptions.h"


void BMRController::calculate()
{
	if (m_isMale)
		BMR = 66.47 + (13.75 * m_weight) + (5.003 * m_height) - (6.755 * m_age);
	else
		BMR = 655.1 + (9.563 * m_weight) + (1.85 * m_height) - (4.676 * m_age);

	double multipliers[5] = { 1.2, 1.375, 1.55, 1.725, 1.9 };
	BMR *= multipliers[m_activityLevel];

	QString msg = QString("Twoje dzienne zapotrzebowanie kaloryczne: %1 kcal").arg(BMR);
	setResultMessage(msg);
}

void BMRController::exportToFile()
{
	const char* activityLevels[] = { "znikomy", "niski", "przecietny", "wysoki", "bardzo wysoki" };
	
	std::map<std::string, std::any> myData;
	myData["naglowek"] = "Zapotrzebowanie kaloryczne";
	myData["wzrost"] = m_height;
	myData["waga"] = m_weight;
	myData["wiek"] = m_age;
	myData["wzrost"] = m_height;
	myData["plec"] = (m_isMale ? "M" : "K");
	myData["poziom_aktywnosci"] = activityLevels[m_activityLevel];
	myData["wynik"] = BMR;

	DataIO dataIO;
	try
	{
		dataIO.ExportToFile(myData, "zapotrzebowanie_kaloryczne");
	}
	catch (std::ios_base::failure& e)
	{
		setResultMessage(e.what());
	}
}

BMRController::BMRController(QObject* parent) : QObject(parent)
{
	m_age = 14;
	m_height = 185.9;
	m_weight = 95.14;
	m_isMale = true;
	m_activityLevel = 0;
	m_resultMessage = "";

	calculate();
}

int BMRController::getAge()
{
	return m_age;
}

double BMRController::getHeight()
{
	return m_height;
}

double BMRController::getWeight()
{
	return m_weight;
}

bool BMRController::getIsMale()
{
	return m_isMale;
}

int BMRController::getActivityLevel()
{
	return m_activityLevel;
}

QString BMRController::getResultMessage()
{
	return m_resultMessage;
}

void BMRController::setAge(int a)
{
	try
	{
		if (a <= 0 || a >= 150)
			throw AgeInputException();

		if (m_age == a)
			return;

		ageInputGood = true;

		if (!weightInputGood || !heightInputGood)
			throw AnyInputException();

		m_age = a;
		calculate();
		emit ageChanged(m_age);
	}
	catch (AgeInputException e)
	{
		ageInputGood = false;
		setResultMessage(e.what());
	}
	catch (AnyInputException e)
	{
		setResultMessage(e.what());
	}
}

void BMRController::setHeight(double h)
{
	try
	{
		if (isnan(h) || h <= 0 || h >= 300)
			throw HeightInputException();

		if (m_height == h)
			return;

		heightInputGood = true;

		if (!ageInputGood || !weightInputGood)
			throw AnyInputException();

		m_height = h;
		calculate();
		emit heightChanged(m_height);
	}
	catch (HeightInputException e)
	{
		heightInputGood = false;
		setResultMessage(e.what());
	}
	catch (AnyInputException e)
	{
		setResultMessage(e.what());
	}
}

void BMRController::setIsMale(bool i)
{
	try
	{
		if (m_isMale == i)
			return;

		if (!ageInputGood || !heightInputGood || !weightInputGood)
			throw AnyInputException();

		m_isMale = i;
		emit isMaleChanged(m_isMale);
		calculate();
	}
	catch (AnyInputException e)
	{
		setResultMessage(e.what());
	}
}

void BMRController::setWeight(double w)
{
	try
	{
		if (isnan(w) || w <= 0 || w >= 500)
			throw WeightInputException();

		if (m_weight == w)
			return;

		weightInputGood = true;

		if (!ageInputGood || !heightInputGood)
			throw AnyInputException();

		m_weight = w;
		calculate();
		emit weightChanged(m_weight);
	}
	catch (WeightInputException e)
	{
		weightInputGood = false;
		setResultMessage(e.what());
	}
	catch (AnyInputException e)
	{
		setResultMessage(e.what());
	}
}

void BMRController::setActivityLevel(int a)
{
	try
	{
		if (m_activityLevel == a)
			return;

		if (!ageInputGood || !heightInputGood || !weightInputGood)
			throw AnyInputException();

		m_activityLevel = a;
		calculate();
		emit activityLevelChanged(m_activityLevel);
	}
	catch (AnyInputException e)
	{
		setResultMessage(e.what());
	}
}

void BMRController::setResultMessage(QString m)
{
	if (m_resultMessage == m)
		return;

	m_resultMessage = m;
	emit resultMessageChanged(m_resultMessage);
}