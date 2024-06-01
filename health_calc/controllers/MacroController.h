#pragma once

#include <QObject>
#include <DataIO.h>
#include <map>
#include <any>

class MacroController : public QObject
{
	Q_OBJECT

		Q_PROPERTY(double BMR READ getBMR WRITE setBMR NOTIFY BMRChanged)
		Q_PROPERTY(QString resultMessage READ getResultMessage WRITE setResultMessage NOTIFY resultMessageChanged)

	double m_BMR;
	QString m_resultMessage;

	double carb, prot, fat;

	void calculate();
public:
	MacroController(QObject* parent, DataCourier* courier);

	Q_INVOKABLE void exportToFile(QString path);

	double getBMR();
	QString getResultMessage();

public slots:
	void setBMR(double b);
	void setResultMessage(QString m);

signals:
	void BMRChanged(double b);
	void resultMessageChanged(QString m);
};