#ifndef SYSTEM_H
#define SYSTEM_H
#include <QtWidgets>
#include "game.h"
#include "menu.h"
#include "view.h"
#include <QThread>
#include <ui_formmenu.h>

class System : public QGraphicsScene
{
private:
    Menu* menu;
public:
    System();
};

#endif // SYSTEM_H
