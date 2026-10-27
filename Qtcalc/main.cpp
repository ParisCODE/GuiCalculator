#include "stdafx.h"
#include "Qtcalc.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Qtcalc window;
    window.show();
    return app.exec();
}
