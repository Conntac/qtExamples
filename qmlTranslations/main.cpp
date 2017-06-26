#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTranslator>
#include <QDebug>
#include "translationmanager.h"



int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    TranslationManager translationMgr;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("translator", &translationMgr);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;



    QObject *window = engine.rootObjects().first();
    QObject::connect(window, SIGNAL(langChangePressed(QString)), &translationMgr, SLOT(changeTranslator(QString)));

//    Alternative to the Connections element in main.qml
//    QObject::connect(&translationMgr, &TranslationManager::translatorChanged, [&](){
//        QMetaObject::invokeMethod(window, "reload");
//        window->setProperty("title", app.translate("main","Hello World"));
//    }
//    );

    return app.exec();
}
