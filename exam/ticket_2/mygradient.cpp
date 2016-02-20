#include "mygradient.h"

#include <QPaintEvent>
#include <QPainter>
#include <QConicalGradient>
#include <QPen>

#define size 4

MyGradient::MyGradient(QWidget*parent):
    QWidget(parent)
{}
MyGradient::~MyGradient()
{
}

void MyGradient::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QConicalGradient gradient(width() / 2, height() / 2, 0);
    gradient.setColorAt(0, Qt::red);
    gradient.setColorAt(0.4, Qt::green);
    gradient.setColorAt(0.8, Qt::blue);
    gradient.setColorAt(1, Qt::red);

    painter.setBrush(gradient);
    painter.drawRect(rect());
    painter.setRenderHint(QPainter::Antialiasing, true);

    QBrush brush(Qt::red, Qt::Dense4Pattern);
    painter.fillRect(10 * size, 10* size, 100* size, 100* size, brush);
    painter.eraseRect(20* size, 20* size, 80* size, 80* size);

    int n = 8;
    QPointF a[n];
    for (int i = 0; i < n; ++i) {
        qreal fAngle = 2.3 * 3.14 * i / n;
        qreal x = (50 + cos(fAngle) * 40)*size;
        qreal y = (50 + sin(fAngle) * 40)*size;
        a[i] = QPointF(x, y);
    }
    painter.drawPolyline(a, n);
}

