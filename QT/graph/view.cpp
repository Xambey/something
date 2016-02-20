#include "view.h"

#include <QPainter>
#include <QMouseEvent>

View::View(QWidget *parent)
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    pos = QPoint(width()/2, height()/2);
    zoom = 1;
}

void View::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}

void View::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    painter.setPen(palette().dark().color());
    painter.setBrush(brush);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.save();
    painter.translate(pos);
    painter.scale(zoom,-zoom);

    painter.drawLine(-width()/2-pos.x(),    0,  width()-pos.x(),0);
    painter.drawLine(0, -height()+pos.y(),  0, height()/2+pos.y());
    painter.drawPath(path);

    painter.restore();
}

void View::mousePressEvent(QMouseEvent * event)
{
    dragEnable = true;
    dragStart = event->pos();
}

void View::mouseMoveEvent(QMouseEvent * event)
{
    if(dragEnable)
    {
        pos -= dragStart - event->pos();
        update();
        dragStart=event->pos();
    }
}

void View::wheelEvent(QWheelEvent * event)
{
    zoom += event->delta()/240.0*zoom;
    if(zoom<0.001)
        zoom=0.001;
    update();
}






