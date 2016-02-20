#include <QtWidgets>
#include "mygradient.h"

int main(int argc, char**argv)
{
    QApplication app(argc, argv);

    MyGradient wgt;
    wgt.show();

    return app.exec();
}
