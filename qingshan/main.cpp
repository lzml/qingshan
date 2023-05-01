#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <UIhandler/dlgmain.h>
#include "win/regEdit.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //???
    regEdit::Instance();


    qmlRegisterType<DlgMain>("DlgMain", 1,0,"DLgMain");

    QQmlApplicationEngine engine;
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("qingshan", "Main");

    return app.exec();
}
