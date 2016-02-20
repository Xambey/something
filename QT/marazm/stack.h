#ifndef STACK_H
#define STACK_H
#include <QStackedWidget>

class stack: QObject
{
public:
    Q_OBJECT
    stack();

signals:
    void clicked();
public slots:
    setCurrentWidget();
};

#endif // STACK_H
