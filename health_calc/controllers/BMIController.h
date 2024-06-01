#pragma once

#include <QObject>
#include <DataIO.h>
#include <map>
#include <any>

class BMIController : public QObject
{
	Q_OBJECT

	Q_PROPERTY(double height READ getHeight WRITE setHeight NOTIFY heightChanged)
	Q_PROPERTY(double weight READ getWeight WRITE setWeight NOTIFY weightChanged)
	Q_PROPERTY(QString resultMessage READ getResultMessage WRITE setResultMessage NOTIFY resultMessageChanged)
	Q_PROPERTY(QString rectColor READ getRectColor WRITE setRectColor NOTIFY rectColorChanged)

	double m_height;
	double m_weight;
	QString m_resultMessage;
	QString m_rectColor;

	double BMI;

	// validation flags
	bool heightInputGood = true;
	bool weightInputGood = true;

	void calculate();
public:
	BMIController(QObject* parent);

	Q_INVOKABLE void exportToFile(QString path);

	double getHeight();
	double getWeight();
	QString getResultMessage();
	QString getRectColor();

public slots:
	void setHeight(double h);
	void setWeight(double w);
	void setResultMessage(QString m);
	void setRectColor(QString c);

signals:
	void heightChanged(double h);
	void weightChanged(double w);
	void resultMessageChanged(QString m);
	void rectColorChanged(QString c);
};