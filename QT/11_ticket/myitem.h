#ifndef MYITEM_H
#define MYITEM_H

#include <QtWidgets>
#include<QGraphicsEllipseItem>


class MyItem : public QGraphicsEllipseItem
{
public:
   // MyItem ( qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = 0);

    QPointF past;
//    virtual void paint(QPainter* ppainter,
//    const QStyleOptionGraphicsItem*,
//    QWidget*
//    )
//    {
//        ppainter->save();
//        //ppainter->setPen(QPen(Qt::blue, nPenWidth));
//        ppainter->drawEllipse(-10, -10, 20, 20);
//        ppainter->restore();
//    }
    //virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* pe)
    {
        QApplication::setOverrideCursor(Qt::PointingHandCursor);
        QGraphicsItem::mousePressEvent(pe);
    }
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* pe)
    {
        QApplication::restoreOverrideCursor();
        QGraphicsItem::mouseReleaseEvent(pe);
    }

    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value)
    {
        if (change != ItemPositionChange && scene()) {
            past = value.toPointF();
            scene()->itemAt(300,0,QTransform())->moveBy(past.rx(),past.ry());
        }
        return QGraphicsItem::itemChange(change, value);
    }

};

#endif // MYITEM_H
