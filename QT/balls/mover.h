#ifndef MOVER_H
#define MOVER_H

#include <QObject>
#include "line.h"

class Mover : public QObject
{
    Q_OBJECT
    BallLine* target;
    float in, to;
    bool invert;
public:
    Mover(BallLine* target, float in, float to);

public slots:
    void onTick(int);
};

#endif // MOVER_H
