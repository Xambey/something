#include "mypainter.h"
#include <QPainter>
MyPainter::MyPainter(QWidget *p)
{
}

void MyPainter::paintEvent(QPaintEvent *)
{
    QPainter painter(this);


    painter.begin(this);
    painter.save();
    painter.translate(200,400);
    painter.restore();
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QBrush(Qt::black, Qt::BDiagPattern));
    painter.setPen(QPen(Qt::blue, 4));
    painter.drawPie(QRect(10, 10, 110, 70), 90 * 16, 270 * 16);
    painter.end();
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QBrush(Qt::green, Qt::CrossPattern));
    painter.setPen(QPen(Qt::red, 3, Qt::DotLine));
    painter.drawEllipse(QRect(40, 40, 140, 90));
    painter.end();
}
