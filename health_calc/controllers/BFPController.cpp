#include "BFPController.h"
#include "CustomExceptions.h"

void BFPController::calculate()
{
	if (m_isMale)
	{
		BFP = (1.20 * m_weight / ((m_height / 100) * (m_height / 100))) + (0.23 * m_age) - 16.2;
	}
	else
	{
		BFP = (1.20 * m_weight / ((m_height / 100) * (m_height / 100))) + (0.23 * m_age) - 5.4;
	}
	
	if (m_isMale)
	{
		if (m_age < 40)
		{
			if (BFP < 8)
			{
				QString msg = QString("Twoje BFP: %1 %\nZa niskie").arg(BFP, 0, 'f', 2);
				setResultMessage(msg);
			}
			else if (BFP < 20)
			{
				QString msg = QString("Twoje BFP: %1 %\nW normie").arg(BFP, 0, 'f', 2);
				setResultMessage(msg);
			}
			else
			{
				QString msg = QString("Twoje BFP: %1 %\nZa wysokie").arg(BFP, 0, 'f', 2);
				setResultMessage(msg);
			}
		}
		else if (m_age < 60)
		{
			if (BFP < 11)
			{
				QString msg = QString("Twoje BFP: %1 %\nZa niskie").arg(BFP, 0, 'f', 2);
				setResultMessage(msg);
			}
			else if (BFP < 22)
			{
				QString msg = QString("Twoje BFP: %1 %\nW normie").arg(BFP, 0, 'f', 2);
				setResultMessage(msg);
			}
			else
			{
				QString msg = QString("Twoje BFP: %1 %\nZa wysokie").arg(BFP, 0, 'f', 2);
				setResultMessage(msg);
			}
		}
		else
		{
			if (BFP < 13)
			{
				QString msg = QString("Twoje BFP: %1 %\nZa niskie").arg(BFP, 0, 'f', 2);
				setResultMessage(msg);
			}
			else if (BFP < 25)
			{
				QString msg = QString("Twoje BFP: %1 %\nW normie").arg(BFP, 0, 'f', 2);
				setResultMessage(msg);
			}
			else
			{
				QString msg = QString("Twoje BFP: %1 %\nZa wysokie").arg(BFP, 0, 'f', 2);
				setResultMessage(msg);
			}
		}
	}
	else
	{
			if (m_age < 40)
		{
			if (BFP < 21)
			{
				QString msg = QString("Twoje BFP: %1 %\nZa niskie").arg(BFP, 0, 'f', 2);
				setResultMessage(msg);
			}
			else if (BFP < 33)
			{
				QString msg = QString("Twoje BFP: %1 %\nW normie").arg(BFP, 0, 'f', 2);
				setResultMessage(msg);
			}
			else
			{
				QString msg = QString("Twoje BFP: %1 %\nZa wysokie").arg(BFP, 0, 'f', 2);
				setResultMessage(msg);
			}
		}
		else if (m_age < 60)
		{
			if (BFP < 23)
			{
				QString msg = QString("Twoje BFP: %1 %\nZa niskie").arg(BFP, 0, 'f', 2);
				setResultMessage(msg);
			}
			else if (BFP < 34)
			{
				QString msg = QString("Twoje BFP: %1 %\nW normie").arg(BFP, 0, 'f', 2);
				setResultMessage(msg);
			}
			else
			{
				QString msg = QString("Twoje BFP: %1 %\nZa wysokie").arg(BFP, 0, 'f', 2);
				setResultMessage(msg);
			}
		}
		else
		{
			if (BFP < 24)
			{
				QString msg = QString("Twoje BFP: %1 %\nZa niskie").arg(BFP, 0, 'f', 2);
				setResultMessage(msg);
			}
			else if (BFP < 36)
			{
				QString msg = QString("Twoje BFP: %1 %\nW normie").arg(BFP, 0, 'f', 2);
				setResultMessage(msg);
			}
			else
			{
				QString msg = QString("Twoje BFP: %1 %\nZa wysokie").arg(BFP, 0, 'f', 2);
				setResultMessage(msg);
			}
		}
	}
}

void BFPController::exportToFile(QString path)
{
	std::string finalPath = path.remove(0, 8).toStdString() + "/bfp.csv";

	std::map<std::string, std::any> myData;
	myData["naglowek"] = "BFP";
	myData["wzrost"] = m_height;
	myData["waga"] = m_weight;
	myData["wiek"] = m_age;
	myData["plec"] = (m_isMale ? "M" : "K");
	myData["wynik"] = BFP;

	DataIO dataIO;
	try
	{
		dataIO.exportToFile(myData, finalPath);
		setResultMessage("Dane zapisane w pliku bfp.csv");
	}
	catch (std::ios_base::failure& e)
	{
		setResultMessage(e.what());
	}
}

BFPController::BFPController(QObject* parent, DataCourier* courier) : QObject(parent)
{
	m_age = courier->getAge();
	m_height = courier->getHeight();
	m_weight = courier->getWeight();
	m_isMale = courier->getIsMale();
	m_resultMessage = "";

	calculate();
}

int BFPController::getAge()
{
	return m_age;
}

double BFPController::getHeight()
{
	return m_height;
}

double BFPController::getWeight()
{
	return m_weight;
}

bool BFPController::getIsMale()
{
	return m_isMale;
}

QString BFPController::getResultMessage()
{
	return m_resultMessage;
}

void BFPController::setAge(int a)
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

void BFPController::setHeight(double h)
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

void BFPController::setIsMale(bool i)
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

void BFPController::setWeight(double w)
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

void BFPController::setResultMessage(QString m)
{
	if (m_resultMessage == m)
		return;

	m_resultMessage = m;
	emit resultMessageChanged(m_resultMessage);
}