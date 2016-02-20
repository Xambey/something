#include <QtWidgets>
#include "myitem.h"
#include "myview.h"

int main(int argc, char**argv)
{

    //ВНИМАНИЕ!
    // ЭТО 6 и 8 БиЛЕТЫ Вместе, ПОТОМУ ЧТО МНЕ ЛЕНЬ ДЕЛАТЬ ЕЩЕ ОДНУ СЦЕНУ:3
    //РЕГУЛЯРНЫЕ ВЫРАЖЕНИЯ ОТСУТСТВУЮТ Т.к МНЕ БЫЛО ЛЕНЬ :)
    //ТАМ ВСЕ ИЗИ, САМ СДЕЛАЕШЬ СТР 88 Qt 4.8 M.Shlee



    QApplication app(argc, argv);


    QCheckBox* check = new QCheckBox("&Check Box");
    QRadioButton* Red = new QRadioButton("&Red");
    QRadioButton* Green = new QRadioButton("&Green");
    QPushButton* button = new QPushButton("&Button");

    QGraphicsScene scene(QRectF(-100, -100, 300, 300));
    QGraphicsView view(&scene);

    QGraphicsRectItem* pRectItem = new QGraphicsRectItem;
    pRectItem->setPen(QPen(Qt::black));
    pRectItem->setBrush(QBrush(Qt::red));
    pRectItem->setRect(QRectF(-30, -30, 120, 80));
    pRectItem->setFlags(QGraphicsItem::ItemIsMovable);
    scene.addItem(pRectItem);

    QGraphicsPixmapItem* pPixmapItem =
            scene.addPixmap(QPixmap("linux.jpg"));
    pPixmapItem->setFlags(QGraphicsItem::ItemIsMovable);

    QGraphicsTextItem* pTextItem =
            scene.addText("Move us with your mouse");
    pTextItem->setFlags(QGraphicsItem::ItemIsMovable);
    pTextItem->setParentItem(pPixmapItem);
    QGraphicsLineItem* pLineItem =
            scene.addLine(QLineF(-10, -10, -80, -80), QPen(Qt::green, 10));
    pLineItem->setFlags(QGraphicsItem::ItemIsMovable);
    view.show();


    QWidget wgt;
    QGraphicsScene scene2(QRectF(-100, -100, 640, 480));

    MyView* pView = new MyView(&scene);


    pView->setRenderHint(QPainter::Antialiasing, true);

    MyItem* pSimpleItem = new MyItem();
    scene2.addItem(pSimpleItem);
    pSimpleItem->setPos(0, 0);
    pSimpleItem->setFlags(QGraphicsItem::ItemIsMovable);

    QGraphicsPixmapItem* pPixmapItem2 =
            scene2.addPixmap(QPixmap("linux.jpg"));
    pPixmapItem2->setParentItem(pSimpleItem);
    pPixmapItem2->setFlags(QGraphicsItem::ItemIsMovable);

    QVBoxLayout* lay = new QVBoxLayout;
    lay->addWidget(pView);
    lay->addWidget(check);
    lay->addWidget(Green);
    lay->addWidget(Red);
    lay->addWidget(button);
    wgt.setLayout(pvbxLayout);

    wgt.show();

    return app.exec();
}
