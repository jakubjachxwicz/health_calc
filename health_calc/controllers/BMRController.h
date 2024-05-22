#pragma once

#include <QObject>
#include <DataIO.h>
#include <map>
#include <any>

class BMRController : public QObject
{
	Q_OBJECT

	Q_PROPERTY(int age READ getAge WRITE setAge NOTIFY ageChanged)
	Q_PROPERTY(double height READ getHeight WRITE setHeight NOTIFY heightChanged)
	Q_PROPERTY(double weight READ getWeight WRITE setWeight NOTIFY weightChanged)
	Q_PROPERTY(bool isMale READ getIsMale WRITE setIsMale NOTIFY isMaleChanged)
	Q_PROPERTY(int activityLevel READ getActivityLevel WRITE setActivityLevel NOTIFY activityLevelChanged)
	Q_PROPERTY(QString resultMessage READ getResultMessage WRITE setResultMessage NOTIFY resultMessageChanged)


	int m_age;
	double m_height;
	double m_weight;
	bool m_isMale;
	int m_activityLevel;
	QString m_resultMessage;

	double BMR;

	// validation flags
	bool ageInputGood = true;
	bool heightInputGood = true;
	bool weightInputGood = true;

	void calculate();
public:
	BMRController(QObject *parent);

	Q_INVOKABLE void exportToFile();

	int getAge();
	double getHeight();
	double getWeight();
	bool getIsMale();
	int getActivityLevel();
	QString getResultMessage();

public slots:
	void setAge(int a);
	void setHeight(double h);
	void setWeight(double w);
	void setIsMale(bool i);
	void setActivityLevel(int a);
	void setResultMessage(QString m);

signals:
	void ageChanged(int a);
	void heightChanged(double h);
	void weightChanged(double w);
	void isMaleChanged(bool i);
	void activityLevelChanged(int a);
	void resultMessageChanged(QString m);
};