#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "map.h"
class Player: public QWidget
{
    Q_OBJECT
public:
    explicit Player(QWidget* parent = 0);

signals:

public slots:
};

#endif // PLAYER_H
