#include "BMRController.h"


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
	if (m_age == a)
		return;
	
	m_age = a;
	calculate();
	emit ageChanged(m_age);
}

void BMRController::setHeight(double h)
{
	if (m_height == h)
		return;

	m_height = h;
	calculate();
	emit heightChanged(m_height);
}

void BMRController::setIsMale(bool i)
{
	if (m_isMale == i)
		return;
	
	m_isMale = i;
	emit isMaleChanged(m_isMale);
	calculate();
}

void BMRController::setWeight(double w)
{
	if (m_weight == w)
		return;
	
	m_weight = w;
	calculate();
	emit weightChanged(m_weight);
}

void BMRController::setActivityLevel(int a)
{
	if (m_activityLevel == a)
		return;
	
	m_activityLevel = a;
	calculate();
	emit activityLevelChanged(m_activityLevel);
}

void BMRController::setResultMessage(QString m)
{
	if (m_resultMessage == m)
		return;

	m_resultMessage = m;
	emit resultMessageChanged(m_resultMessage);
}
