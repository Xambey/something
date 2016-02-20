#include "base.h"
#include <QApplicationStateChangeEvent>
#include <QDebug>
#include <circle.h>
#include <rect.h>
#include <QApplication>
int main(int argc, char**argv)
{
    QApplication app(argc, argv);

    Base base();
    qDebug() << base.put();

    Circle circle();
    qDebug() << circle.put();

    Rect rect();
    qDebug() << rect.put();
    return app.exec();
}
