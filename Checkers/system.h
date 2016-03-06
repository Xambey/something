#ifndef SYSTEM_H
#define SYSTEM_H
#include <QtWidgets>
#include "menu.h"
#include "view.h"
#include <QThread>

class System : public QGraphicsScene
{
private:
    Menu* menu;
public:
    explicit System(QWidget* parent = 0);
};

#endif // SYSTEM_H
