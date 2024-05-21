#pragma once

#include <QObject>

class BMIController : public QObject
{
	Q_OBJECT

		Q_PROPERTY(double height READ getHeight WRITE setHeight NOTIFY heightChanged)
		Q_PROPERTY(double weight READ getWeight WRITE setWeight NOTIFY weightChanged)
		Q_PROPERTY(QString resultMessage READ getResultMessage WRITE setResultMessage NOTIFY resultMessageChanged)

	double m_height;
	double m_weight;
	QString m_resultMessage;

	double BMI;

	void calculate();
public:
	BMIController(QObject* parent);

	double getHeight();
	double getWeight();
	QString getResultMessage();

public slots:
	void setHeight(double h);
	void setWeight(double w);
	void setResultMessage(QString m);

signals:
	void heightChanged(double h);
	void weightChanged(double w);
	void resultMessageChanged(QString m);
};