#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include"./Control/control.h"




int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    MyListViewModel *listModel=new MyListViewModel();
    Control *control=new Control(listModel);
    control->init();
    engine.rootContext()->setContextProperty("control", control);
    engine.rootContext()->setContextProperty("ListViewModel",listModel);
    const QUrl url(u"qrc:/ShareBook_Prototype/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
