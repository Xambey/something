#include <QtWidgets>
#include "system.h"
#include "menu.h"

int main(int argc, char** argv)
{
    QApplication app(argc,argv);
    new System;
    return app.exec();
}
