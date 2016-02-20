#include <QtWidgets>
class QGraphicsEllipseItem;


int main(int argc, char**argv)
{
    QApplication app(argc,argv);

    QGraphicsScene scene;
    QGraphicsEllipseItem* item1 = scene.addEllipse(0,0,100,100,QPen(),QBrush(Qt::black));
    QGraphicsEllipseItem* item2 = scene.addEllipse(0,0,100,100,QPen(),QBrush(Qt::black));

    QPointF pos(0,0);
    if(item1->pos() != pos)
    {
        item2->moveBy(0,0);
    }
        return app.exec();
}

