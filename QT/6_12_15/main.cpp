#include <QLabel>
#include <QtGui>
#include <QApplication>
#include <QSplitter>
#include <QTextEdit>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QCheckBox>
#include <QGroupBox>
#include<QRadioButton>
#include <QWidget>
#include <QGridLayout>
#include <QAbstractSlider>
#include <QDial>
#include <QSlider>
#include <cstdlib>
#include <ctime>
#include <QWidget>
#include <QSyntaxHighlighter>
#include <QtGui>
#include <QComboBox>
#include <QStringList>
#include <QTableWidget>
#include <QToolBox>
#include <QVariant>
#include <QAbstractItemModel>
#include <QTreeView>
#include <QListView>
#include <QItemDelegate>
#include <iostream>
#include <QStandardItemModel>
#include <QtGui>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include "C:\Users\Andrey\Documents\QT\1_12_15\simpleitem.h"
#include "C:\Users\Andrey\Documents\QT\1_12_15\myview.h"
//#include
#include <QProgressBar>
#include <QGraphicsProxyWidget>

    int main (int argc, char** argv)
    {
        QApplication app(argc, argv);


        QGraphicsScene scene(QRectF(-200, -200, 300, 300));
        QWidget wgt;
        MyView* pView = new MyView(&scene);
        pView->setRenderHint(QPainter::Antialiasing, true);
        wgt.show();

        //wgt.setLayout(&lay);
        //scene.addWidget(pView);
        //wgt.show();
      // view.show();
       //pView->show();
       //wgt.show();
//        QGraphicsPixmapItem* pPixmapItem =
//                scene.addPixmap(QPixmap("haus.jpg"));
//        pPixmapItem->setFlags(QGraphicsItem::ItemIsMovable);

//        QGraphicsTextItem* pTextItem =
//                scene.addText("Move us with your mouse");
//        pTextItem->setFlags(QGraphicsItem::ItemIsMovable);
//        pTextItem->setParentItem(pPixmapItem);
//        QGraphicsLineItem* pLineItem =
//                scene.addLine(QLineF(-10, -10, -80, -80), QPen(Qt::red, 2));
//        pLineItem->setFlags(QGraphicsItem::ItemIsMovable);
//        view.show();


//        QWidget wgt;
//        QGraphicsScene scene2(QRectF(-100, -100, 640, 480));
//        //MyView* pView = new MyView(&scene2);
//        MyView* pView = new MyView(&scene);
//        QPushButton* pcmdZoomIn = new QPushButton("&Zoom In");
//        QPushButton* pcmdZoomOut = new QPushButton("Z&oom Out");
//        QPushButton* pcmdRotateLeft = new QPushButton("&Rotate Left");
//        QPushButton* pcmdRotateRight = new QPushButton("Ro&tate Right");

//        pView->setRenderHint(QPainter::Antialiasing, true);

//        SimpleItem* pSimpleItem = new SimpleItem();
//        scene2.addItem(pSimpleItem);
//        pSimpleItem->setPos(0, 0);
//        pSimpleItem->setFlags(QGraphicsItem::ItemIsMovable);

//        QGraphicsPixmapItem* pPixmapItem2 =
//                scene2.addPixmap(QPixmap("haus.jpg"));
//        pPixmapItem2->setParentItem(pSimpleItem);
//        pPixmapItem2->setFlags(QGraphicsItem::ItemIsMovable);
//        QObject::connect(pcmdZoomIn, SIGNAL(clicked()),pView, SLOT(slotZoomIn()));
//        QObject::connect(pcmdZoomOut, SIGNAL(clicked()),pView, SLOT(slotZoomOut()));
//        QObject::connect(pcmdRotateLeft, SIGNAL(clicked()),pView, SLOT(slotRotateLeft()));
//        QObject::connect(pcmdRotateRight, SIGNAL(clicked()),pView, SLOT(slotRotateRight()));

//        //Layout setup
//        QVBoxLayout* pvbxLayout = new QVBoxLayout;
//        pvbxLayout->addWidget(pView);
//        pvbxLayout->addWidget(pcmdZoomIn);
//        pvbxLayout->addWidget(pcmdZoomOut);
//        pvbxLayout->addWidget(pcmdRotateLeft);
//        pvbxLayout->addWidget(pcmdRotateRight);
//        wgt.setLayout(pvbxLayout);
//        wgt.show();


//        QGraphicsScene scene3(QRectF(0, 0, 400, 400));
//        QGraphicsView view3(&scene3);
//        QPushButton cmd("Quit");
//        QGraphicsProxyWidget* pproxyWidget = scene3.addWidget(&cmd);
//        QTransform transform = pproxyWidget->transform();
//        transform.translate(100, 350);
//        transform.rotate(-45, Qt::YAxis);
//        transform.scale(8, 2);
//        pproxyWidget->setTransform(transform);
//        QObject::connect(&cmd, SIGNAL(clicked()), &app, SLOT(quit()));
//        QDial dia;
//        QLineEdit* line = new QLineEdit;
//        line->setText(QString("OLOLOLo I'm a student"));
//        dia.setNotchesVisible(true);
//        pproxyWidget = scene3.addWidget(&dia);

//        transform = pproxyWidget->transform();
//        transform.scale(4, 2);
//        transform.rotate(-45, Qt::YAxis);
//        pproxyWidget->setTransform(transform);


//        pproxyWidget = scene3.addWidget(line);
//        transform = pproxyWidget->transform();
//        transform.translate(150, 300);
//        transform.scale(5, 5);
//        transform.rotate(80, Qt::YAxis);
//        transform.rotate(30, Qt::XAxis);
//        pproxyWidget->setTransform(transform);

//        QProgressBar prb;
//        prb.setFixedSize(500, 40);
//        pproxyWidget = scene3.addWidget(&prb);
//        transform = pproxyWidget->transform();
//        transform.translate(200, 200);
//        transform.scale(2, 2);
//        transform.rotate(80, Qt::YAxis);
//        transform.rotate(30, Qt::XAxis);
//        pproxyWidget->setTransform(transform);
//        QObject::connect(&dia, SIGNAL(valueChanged(int)),&prb, SLOT(setValue(int)));
//        QObject::connect(&dia, SIGNAL(valueChanged(int)),line, SLOT(setText(int)));
     return app.exec();

}
