#include <QApplication>
#include <QTranslator>
#include "MyWindow.h"

#include <iostream>
int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QString locale = QLocale::system().name().section('_', 0, 0);

    std::cout << "locale : " << locale.toStdString() << std::endl;
    std::cout << "transfile : " << app.applicationDirPath().toStdString()+"/Translations/exo-Qt_"+locale.toStdString() << std::endl;

    QTranslator translator;

    translator.load(app.applicationDirPath()+"/Translations/exo-Qt_"+locale);
    app.installTranslator(&translator);


    MyWindow window;
    window.show();

    return app.exec();
}
