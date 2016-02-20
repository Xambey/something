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
#include <QMovie>
#include <QGraphicsRectItem>
#include <QAbstractAnimation>
#include <QGraphicsColorizeEffect>
#include <QVariantAnimation>
#include <QStyle>
#include <QWindow>
#include <QProxyStyle>
#include <QStyleFactory>
#include "myline.h"

#define speed 3000
#define size 108
#define real_size 109.26
#define pos_x 235
#define pos_y 235
#define d_x 142
#define d_y 123


int main(int argc, char** argv)
{
    QApplication app(argc, argv);


    QGraphicsView wgt;
    QGraphicsScene* scene = new QGraphicsScene(&wgt);
    wgt.setScene(scene);
    wgt.setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    QLabel lbl1;
    lbl1.setPixmap(QPixmap("ball.png"));
    lbl1.setGeometry(0,0,size,size);
    lbl1.setParent(&wgt);

    QLabel lbl2;
    lbl2.setPixmap(QPixmap("ball.png"));
    lbl2.setParent(&wgt);
    lbl2.setGeometry(0,0,size,size);


    int of = pos_x;
    QPropertyAnimation* leftball = new QPropertyAnimation(&lbl1, "pos");
    leftball->setDuration(speed);
    leftball->setStartValue(QPoint(of, pos_y));
    leftball->setEndValue(QPoint(of - d_x, pos_y - d_y));
    leftball->setEasingCurve(QEasingCurve::SineCurve);
    //scene->addWidget(new myLine(scene,&wgt));


    of += real_size;
    for(int i = 0; i < 2; i++)
    {
        QLabel* ball = new QLabel();
        ball->setPixmap(QPixmap("ball.png"));
        ball->setGeometry(of, pos_y, size, size);
        ball->setParent(&wgt);
        of += real_size;
    }

    QPropertyAnimation* rightball = new QPropertyAnimation(&lbl2, "pos");
    rightball->setDuration(speed);
    rightball->setStartValue(QPoint(of, pos_y));
    rightball->setEndValue(QPoint(of + d_x, pos_y - d_y));
    lbl2.setGeometry(of, pos_y,size, size);
    rightball->setEasingCurve(QEasingCurve::SineCurve);

    QObject::connect(leftball, SIGNAL(finished()), rightball, SLOT(start()));
    QObject::connect(rightball, SIGNAL(finished()), leftball, SLOT(start()));

    leftball->start();
    wgt.resize(1000, 460);
    wgt.show();




    return app.exec();
}

