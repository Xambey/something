#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include "Counter.h"

int main ( int argc, char ** argv)
{
    QApplication app(argc, argv);

    QLabel lbl( "0"   );
    QLabel lbl2( "0"   );
    QPushButton  cmd( "ADD" );
    Counter      counter(&cmd, 5);
    lbl.show();
    lbl2.show();
    cmd.show();

    QObject::connect(&cmd, SIGNAL(clicked()),&counter, SLOT(slotInc()));

    QObject::connect(&counter, SIGNAL(counterChanged(int)),&lbl ,SLOT(setNum(int)));

    QObject::connect(&counter, SIGNAL(counterChanged(int)),&lbl2 ,SLOT(setNum(int)));

    return app.exec();
}
