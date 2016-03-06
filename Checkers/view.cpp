#include "view.h"

View::View(QWidget *parent): QGraphicsView(parent)
{
}

View::View(QGraphicsScene &scene)
{
    setAutoFillBackground(true);
    setBaseSize(1200,800);
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

