#pragma once

#include <QObject>

class BMRController : public QObject
{
	Q_OBJECT

	Q_PROPERTY(int age READ getAge WRITE setAge NOTIFY ageChanged)
	Q_PROPERTY(double height READ getHeight WRITE setHeight NOTIFY heightChanged)
	Q_PROPERTY(double weight READ getWeight WRITE setWeight NOTIFY weightChanged)


	int m_age;
	double m_height;
	double m_weight;
public:
	BMRController(QObject *parent);

	int getAge();
	double getHeight();
	double getWeight();

public slots:
	void setAge(int a);
	void setHeight(double h);
	void setWeight(double w);

signals:
	void ageChanged(int a);
	void heightChanged(double h);
	void weightChanged(double w);
};