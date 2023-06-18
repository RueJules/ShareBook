#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include"Control/Control.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/ShareBook_Prototype/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    Control *control=new Control();//控制类启动
    control->init(); //初始账户
    control->createNote(); //

    return app.exec();
}
