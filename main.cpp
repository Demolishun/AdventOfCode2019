#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "day01.h"
#include "day02.h"

/*

https://adventofcode.com/

*/

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    /*
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    */

    // days
    //Day01Main(argc, argv);
    Day02Main(argc, argv);

    //return app.exec();
}
