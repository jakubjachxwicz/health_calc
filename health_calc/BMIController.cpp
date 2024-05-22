#include "BMIController.h"
#include "BMRExceptions.h"

void BMIController::calculate()
{
	BMI = m_weight / ((m_height/100) * (m_height/100));

	if (BMI < 18.5)
	{
		QString msg = QString("Twoje BMI: %1\nNiedowaga").arg(BMI);
		setResultMessage(msg);
	}
	else if (BMI < 25)
	{
		QString msg = QString("Twoje BMI: %1\nNorma").arg(BMI);
		setResultMessage(msg);
	}
	else if (BMI < 30)
	{
		QString msg = QString("Twoje BMI: %1\nNadwaga").arg(BMI);
		setResultMessage(msg);
	}
	else
	{
		QString msg = QString("Twoje BMI: %1\nOtylosc").arg(BMI);
		setResultMessage(msg);
	}
}

BMIController::BMIController(QObject* parent) : QObject(parent)
{
	m_height = 198;
	m_weight = 98;
	m_resultMessage = "";

	calculate();
}

double BMIController::getHeight()
{
	return m_height;
}

double BMIController::getWeight()
{
	return m_weight;
}

QString BMIController::getResultMessage()
{
	return m_resultMessage;
}

void BMIController::setHeight(double h)
{
	try
	{
		if (isnan(h) || h <= 0 || h >= 300)
			throw HeightInputException();

		if (m_height == h)
			return;

		heightInputGood = true;

		if (!weightInputGood)
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

void BMIController::setWeight(double w)
{
	try
	{
		if (isnan(w) || w <= 0 || w >= 500)
			throw WeightInputException();

		if (m_weight == w)
			return;

		weightInputGood = true;

		if (!heightInputGood)
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

void BMIController::setResultMessage(QString m)
{
	if (m_resultMessage == m)
		return;

	m_resultMessage = m;
	emit resultMessageChanged(m_resultMessage);
}