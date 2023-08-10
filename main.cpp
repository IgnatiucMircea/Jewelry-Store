#include "mainwindow.h"
#include "Repository.h"
#include "Controller.h"
#include "CLI.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
using std::cout;

int main(int argc, char *argv[])
{
    Jewelry_Product j("bnbnok", "lantisor", 10000, 1000, 30);
    Jewelry_Product j1("2477u", "bratara", 2500, 500, 10);
    Jewelry_Product j2("xxz10", "inel", 450, 100, 4);
    Repository repo;
    Controller c{ repo };
    c.add(j);
    c.add(j1);
    c.add(j2);
    // CLI UI{ c };
    // UI.run_ui();
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "project_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w{nullptr, &c};
    w.show();
    _CrtDumpMemoryLeaks();
    return a.exec();
}
