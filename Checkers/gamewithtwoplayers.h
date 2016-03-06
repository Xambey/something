#ifndef GAMEWITHTWOPLAYERS_H
#define GAMEWITHTWOPLAYERS_H

#include <QWidget>
#include <QtWidgets>
#include "cell.h"
#include "map.h"



class GameWithTwoPlayers : public QWidget
{
    Q_OBJECT
public:
    explicit GameWithTwoPlayers(QGraphicsScene* scene,QWidget *parent = 0);
private:
    MyMap* map;
    QWidget* Menu;
    //Cell* listCells[CountCells];
};

#endif // GAMEWITHTWOPLAYERS_H
