#ifndef GAME_H
#define GAME_H
#include "menu.h"
#include "map.h"

#include <QtWidgets>

class Game : public QWidget
{
public:
    Game();
    QGraphicsScene CreateScene();
private:
    QGraphicsScene scene;
signals:

public slots:
};

#endif // GAME_H
