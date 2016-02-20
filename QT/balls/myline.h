#ifndef MYLINE_H
#define MYLINE_H
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPainter>

class myLine: public QObject, QGraphicsLineItem
{
    Q_OBJECT
public:
    myLine(QGraphicsScene*scene, QGraphicsView* parent = 0);

    void adjust();

    enum { Type = UserType + 2 };
    int type() const Q_DECL_OVERRIDE { return Type; }
protected:
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;


};

#endif // MYLINE_H
