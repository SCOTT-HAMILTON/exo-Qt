#include <QApplication>
#include <QTranslator>
#include "MyWindow.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QString locale = QLocale::system().name().section('_', 0, 0);

    QTranslator translator;

    translator.load(app.applicationDirPath()+"/Translations/exo-Qt_"+locale);
    app.installTranslator(&translator);


    MyWindow window;
    window.show();

    return app.exec();
}
