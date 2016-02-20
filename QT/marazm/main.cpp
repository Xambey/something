



#include <QtGui>
#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QScrollArea>
#include <QLayout>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QBoxLayout>
#include <QSpacerItem>
#include <QGridLayout>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget wgt;
    wgt.resize(2000, 2000);
    QWidget* pwgt1 = new QWidget(&wgt);
    QPalette pal1;


    pal1.setColor(pwgt1->backgroundRole(), Qt::black);
    pwgt1->setPalette(pal1);
    pwgt1->resize(500, 500);
    pwgt1->move(0, 0);
    pwgt1->setAutoFillBackground(true);
    pwgt1->setCursor(Qt::PointingHandCursor);
    pwgt1->show();

    QWidget* pwgt2 = new QWidget(&wgt);
    QPalette pal2;
    QPixmap pix("stone.jpg");
    QCursor cur(pix);

    pal2.setBrush(pwgt2->backgroundRole(), QBrush(QPixmap("stone.jpg")));
    pwgt2->setPalette(pal2);
    pwgt2->setCursor(Qt::ForbiddenCursor);
    pwgt2->resize(500, 500);
    pwgt2->move(500, 0);
    pwgt2->setAutoFillBackground(true);
    pwgt2->show();

    QFrame* obj = new QFrame(pwgt2);
    obj->setFrameStyle(QFrame::Box||QFrame::Plain);
    obj->setLineWidth(5);
    obj->setFocus();
    //obj->setGeometry(800, 800, 800, 800);
    //obj->autoFillBackground();
    //obj->show();
    //obj->setAutoFillBackground(true);

//    QScrollArea sa(&wgt);
//    sa.setWidget(pwgt2);
//    //sa.resize(8000,8000);
//    sa.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
//    sa.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
//    sa.move(500,0);


    QGridLayout *layount = new QGridLayout;
    //QSpacerItem *p_SpaceItem = new QSpacerItem(32,32,QSizePolicy::Fixed, QSizePolicy::Fixed);
    layount->addWidget(pwgt1, 0, 0);
    //layount->addStretch();
    layount->addWidget(pwgt2, 0, 500);
    //layount->addItem(p_SpaceItem);
    layount->addWidget(obj, 0, 1000);

    wgt.setLayout(layount);


//    QWidget* pwgt3 = new QWidget(&wgt);
//    QPalette pal3;


//    pal3.setColor(pwgt3->backgroundRole(), Qt::blue);
//    pwgt3->setPalette(pal3);
//    pwgt3->resize(500, 500);
//    pwgt3->move(0, 0);
//    pwgt3->setAutoFillBackground(true);
//    pwgt3->setCursor(Qt::PointingHandCursor);
//    pwgt3->show();

//    QStackedWidget *stack = new QStackedWidget(&wgt);
//    stack->addWidget(pwgt1);
//    stack->addWidget(pwgt3);

//    QObject::connect(pwgt1, SIGNAL(clicked()), pwgt3, SLOT(setCurrentWidget(pwgt3)));
//    QObject::connect(pwgt3, SIGNAL(clicked()), pwgt1, SLOT(setCurrentWidget(pwgt1)));

    //stack->show();
    //sa.show();
    wgt.show();
    return app.exec();
}
