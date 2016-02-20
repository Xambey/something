#include "counter.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>

// ----------------------------------------------------------------------
Counter::Counter(QPushButton* cmd, int max) : QObject()
  , m_nValue(0), cmd(cmd), max(max)
{
}
// ----------------------------------------------------------------------
void Counter::slotInc()
{
    emit counterChanged(++m_nValue);
    if (m_nValue == max) {
        if(max == 7)
            exit(0);
        QLabel* lbl = new QLabel("0");
        Counter *counter = new Counter(cmd, 7);
        QObject::connect(counter, SIGNAL(counterChanged(int)),lbl ,SLOT(setNum(int)));
        QObject::disconnect(cmd, SIGNAL(clicked()),this, SLOT(slotInc()));
        QObject::connect(cmd, SIGNAL(clicked()),counter, SLOT(slotInc()));
        lbl->show();
    }
}

