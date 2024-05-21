#include "BMIController.h"
#include "BMRExceptions.h"

void BMIController::calculate()
{
	BMI = m_weight / (m_height * m_height);
	QString msg = QString("Twoje BMI: %2.4").arg(BMI);
	setResultMessage(msg);
}

BMIController::BMIController(QObject* parent) : QObject(parent)
{
	m_height = 169;
	m_weight = 69;
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
	m_height = h;
	calculate();
	emit heightChanged(m_height);
}

void BMIController::setWeight(double w)
{
	m_weight = w;
	calculate();
	emit weightChanged(m_weight);
}

void BMIController::setResultMessage(QString m)
{
	m_resultMessage = m;
	emit resultMessageChanged(m_resultMessage);
}