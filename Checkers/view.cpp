#include "view.h"

View::View(QGraphicsScene &scene)
{
    autoFillBackground();
    setScene(&scene);
}

void View::showEvent(QShowEvent *)
{
    this->move(100,0);
}

void View::resizeEvent(QResizeEvent *)
{
    fitInView(this->scene()->sceneRect());
}

