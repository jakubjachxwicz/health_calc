#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>

#include "controllers/BMRController.h"
#include "controllers/BMIController.h"
#include "controllers/BFPController.h"
#include "controllers/MacroController.h"
#include "controllers/UserController.h"
#include "DataCourier.h"
#include "FileStructureException.h"


int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN) && QT_VERSION_CHECK(5, 6, 0) <= QT_VERSION && QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    app.setWindowIcon(QIcon(":/qt/qml/health_calc/ui/Assets/favicon.png"));

    DataCourier dataCourier;
    DataIO io;
    
    try
    {
        dataCourier = io.readUserData();
    }
    catch (const FileStructureException& e)
    {}
    catch (const std::ios_base::failure& e) 
    {}
    catch (const std::exception& e)
    {}

    BMRController m_BMRHandler(nullptr, &dataCourier);
    BMIController m_BMIHandler(nullptr, &dataCourier);
    BFPController m_BFPHandler(nullptr, &dataCourier);
    MacroController m_MacroHandler(nullptr, &dataCourier);
    UserController m_userHandler(nullptr, &dataCourier);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qt/qml/health_calc/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QQmlContext* context(engine.rootContext());
    context->setContextProperty("BMRHandler", &m_BMRHandler);
    context->setContextProperty("BMIHandler", &m_BMIHandler);
    context->setContextProperty("BFPHandler", &m_BFPHandler);
    context->setContextProperty("MacroHandler", &m_MacroHandler);
    context->setContextProperty("UserHandler", &m_userHandler);

    return app.exec();
}
