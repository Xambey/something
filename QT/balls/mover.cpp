#include "mover.h"
#include "qdebug.h"

Mover::Mover(BallLine* target, float in, float to)
{
    this->target = target;
    this->in = in;
    this->to = to;
    invert = false;
}

void Mover::onTick(int)
{
    qDebug() << "d'";
    if(invert)
    {
        if(target->angine <= in)
            invert = false;
        else
            target->angine -= 1;
    }
    else
    {
        if(target->angine >= to)
            invert = true;
        else
            target->angine += 1;
    }
    target->update();
}
