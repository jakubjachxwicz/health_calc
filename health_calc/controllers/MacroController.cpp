#include "MacroController.h"
#include "CustomExceptions.h"

void MacroController::calculate()
{
	prot = (m_BMR * 0.3) / 4;
	carb = (m_BMR * 0.4) / 4;
	fat = (m_BMR * 0.3) / 9;
	QString msg = QString("Twoje dzienne zapotrzebowanie\nBiałka: %1 g\nWęglowodany: %2 g\nTłuszcze: %3 g")
		.arg(prot, 0, 'f', 2)
		.arg(carb, 0, 'f', 2)
		.arg(fat, 0, 'f', 2);
	setResultMessage(msg);
}

void MacroController::exportToFile(QString path)
{
	std::string finalPath = path.remove(0, 8).toStdString() + "/macro.csv";

	std::map<std::string, std::any> myData;
	myData["naglowek"] = "Makroskładniki";
	myData["BMR"] = m_BMR;
	myData["bialka"] = prot;
	myData["weglowodany"] = carb;
	myData["tluszcze"] = fat;

	DataIO dataIO;
	try
	{
		dataIO.exportToFile(myData, finalPath);
		setResultMessage("Dane zapisane w pliku macro.csv");
	}
	catch (std::ios_base::failure& e)
	{
		setResultMessage(e.what());
	}
}

MacroController::MacroController(QObject* parent, DataCourier* courier) : QObject(parent)
{
	m_BMR = courier->getBmr();
	m_resultMessage = "";

	calculate();
}

double MacroController::getBMR()
{
	return m_BMR;
}

QString MacroController::getResultMessage()
{
	return m_resultMessage;
}

void MacroController::setBMR(double b)
{
		m_BMR = b;
		calculate();
		emit BMRChanged(m_BMR);
}

void MacroController::setResultMessage(QString m)
{
	if (m_resultMessage == m)
		return;

	m_resultMessage = m;
	emit resultMessageChanged(m_resultMessage);
}