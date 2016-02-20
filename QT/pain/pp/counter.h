#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QPushButton>

class Counter : public QObject
{
    Q_OBJECT

private:
    int m_nValue, max;
    QPushButton* cmd;
public:
    Counter(QPushButton *, int);

public slots:
    void slotInc();
signals:
    void counterChanged(int);
};

#endif // COUNTER_H
