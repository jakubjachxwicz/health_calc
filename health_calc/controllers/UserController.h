#pragma once

#include <QObject>
#include "DataCourier.h"


class UserController : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString firstName READ getFirstName WRITE setFirstName NOTIFY firstNameChanged)
	Q_PROPERTY(QString lastName READ getLastName WRITE setLastName NOTIFY lastNameChanged)
	Q_PROPERTY(int age READ getAge WRITE setAge NOTIFY ageChanged)
	Q_PROPERTY(double weight READ getWeight WRITE setWeight NOTIFY weightChanged)
	Q_PROPERTY(double height READ getHeight WRITE setHeight NOTIFY heightChanged)
	Q_PROPERTY(bool isMale READ getIsMale WRITE setIsMale NOTIFY isMaleChanged)

	QString m_firstName;
	QString m_lastName;
	int m_age;
	double m_weight;
	double m_height;
	bool m_isMale;

public:
	UserController(QObject* parent, DataCourier* dc);

	Q_INVOKABLE void save();

	QString getFirstName();
	QString getLastName();
	int getAge();
	double getWeight();
	double getHeight();
	bool getIsMale();

	DataCourier* courier;

public slots:
	void setFirstName(QString fName);
	void setLastName(QString lName);
	void setAge(int a);
	void setWeight(double w);
	void setHeight(double h);
	void setIsMale(bool ismale);

signals:
	void firstNameChanged(QString fName);
	void lastNameChanged(QString fName);
	void ageChanged(int a);
	void weightChanged(double w);
	void heightChanged(double h);
	void isMaleChanged(bool ismale);
};