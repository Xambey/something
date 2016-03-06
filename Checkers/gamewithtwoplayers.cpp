#include "gamewithtwoplayers.h"

GameWithTwoPlayers::GameWithTwoPlayers(QGraphicsScene* scene, QWidget *parent) : QWidget(parent)
{
    map = new MyMap;
    Menu = new QWidget;
    scene->addWidget(map);
}

