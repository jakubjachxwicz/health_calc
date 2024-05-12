#include "BMRController.h"


BMRController::BMRController(QObject* parent) : QObject(parent)
{
	m_age = 65165;
	m_height = 185.9;
	m_weight = 95.14;
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

void BMRController::setAge(int a)
{
	m_age = a;

	emit ageChanged(m_age);
}

void BMRController::setHeight(double h)
{
	m_height = h;

	emit heightChanged(m_height);
}

void BMRController::setWeight(double w)
{
	m_weight = w;

	emit weightChanged(m_weight);
}
