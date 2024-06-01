#pragma once

#include <QObject>
#include <DataIO.h>
#include <map>
#include <any>

class BFPController : public QObject
{
	Q_OBJECT

	Q_PROPERTY(int age READ getAge WRITE setAge NOTIFY ageChanged)
	Q_PROPERTY(double height READ getHeight WRITE setHeight NOTIFY heightChanged)
	Q_PROPERTY(double weight READ getWeight WRITE setWeight NOTIFY weightChanged)
	Q_PROPERTY(bool isMale READ getIsMale WRITE setIsMale NOTIFY isMaleChanged)
	Q_PROPERTY(QString resultMessage READ getResultMessage WRITE setResultMessage NOTIFY resultMessageChanged)
	Q_PROPERTY(QString rectColor READ getRectColor WRITE setRectColor NOTIFY rectColorChanged)

	int m_age;
	double m_height;
	double m_weight;
	bool m_isMale;
	QString m_rectColor;
	QString m_resultMessage;

	double BFP;

	// validation flags
	bool ageInputGood = true;
	bool heightInputGood = true;
	bool weightInputGood = true;

	void calculate();
public:
	BFPController(QObject* parent, DataCourier* courier);

	Q_INVOKABLE void exportToFile(QString path);

	int getAge();
	double getHeight();
	double getWeight();
	bool getIsMale();
	QString getResultMessage();
	QString getRectColor();

public slots:
	void setAge(int a);
	void setHeight(double h);
	void setWeight(double w);
	void setIsMale(bool i);
	void setResultMessage(QString m);
	void setRectColor(QString c);

signals:
	void ageChanged(int a);
	void heightChanged(double h);
	void weightChanged(double w);
	void isMaleChanged(bool i);
	void resultMessageChanged(QString m);
	void rectColorChanged(QString c);
};