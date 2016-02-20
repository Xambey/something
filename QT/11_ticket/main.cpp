
#include <QtWidgets>
//#include "myscene.h"
#include "myitem.h"


#define X1 0
#define Y1 0
#define X2 300
#define Y2 0





int main(int argc, char**argv)
{
    QApplication app(argc,argv);

    QGraphicsScene scene;
    QGraphicsView  view;

    //MyScene scene;
    scene.setSceneRect(0,0,800,600);
    view.setScene(&scene);

    //MyItem* item1 = scene.addEllipse(0,0,100,100, QPen(), QBrush(Qt::red));
    //MyItem* item2 = scene.addEllipse(300,0,100,100, QPen(), QBrush(Qt::blue));
    MyItem* item1 = new MyItem();
    MyItem* item2 = new MyItem();
    item1->setRect(0,0,100,100);
    item2->setRect(300,0,100,100);
   // item1.setPos(QPointF(0,0));
   // item2.setPos(QPointF(300,0));



   // item1->setFlags(QGraphicsItem::ItemIsMovable);
    //item2->setFlags(QGraphicsItem::ItemIsMovable);
    scene.addItem(item1);
   // scene.addItem(item2);
    //QGraphicsEllipseItem* item3 = scene.addEllipse(X1,Y1,100,100, QPen(), QBrush(Qt::red));
    //QGraphicsEllipseItem* item4 = scene.addEllipse(X2,Y2,100,100, QPen(), QBrush(Qt::blue));
    //item3->setFlags(QGraphicsItem::ItemIsMovable);
    //item4->setFlags(QGraphicsItem::ItemIsMovable);
    //QObject::connect(item1,SIGNAL)


    view.resize(800,600);
    view.show();

//    view.setAcceptDrops(true);

//    item1->setAcceptDrops(true);
//    item2->setAcceptDrops(true);

    //item3->setAcceptDrops(true);
    //item4->setAcceptDrops(true);

    return app.exec();
}
