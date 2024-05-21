#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>

#include "DataExports.h"

#include "controllers/BMRController.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN) && QT_VERSION_CHECK(5, 6, 0) <= QT_VERSION && QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    app.setWindowIcon(QIcon(":/qt/qml/health_calc/ui/Assets/favicon.png"));

    BMRController m_BMRHandler(nullptr);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qt/qml/health_calc/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QQmlContext* context(engine.rootContext());
    context->setContextProperty("BMRHandler", &m_BMRHandler);

    return app.exec();
}
