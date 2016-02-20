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

QWidget* styledWidget(QStyle* pstyle)
{
    QGroupBox* pgr = new QGroupBox(pstyle->metaObject()->className());
    //QScrollBar* psbr = new QScrollBar(Qt::Horizontal);
    QCheckBox* pchk = new QCheckBox("&Check Box");
    QSlider* psld = new QSlider(Qt::Horizontal);
    QRadioButton* prad = new QRadioButton("&Radio Button");
    QPushButton* pcmd = new QPushButton("&Push Button");
    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;


    //pvbxLayout->addWidget(psbr);
    pvbxLayout->addWidget(pchk);
    pvbxLayout->addWidget(psld);
    pvbxLayout->addWidget(prad);
    pvbxLayout->addWidget(pcmd);
    pgr->setLayout(pvbxLayout);

    pchk->setStyle(pstyle);
    psld->setStyle(pstyle);
    prad->setStyle(pstyle);
    pcmd->setStyle(pstyle);

    return pgr;
}
//



int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QLabel lbl;
    qApp->setStyleSheet("Ubuntu Linux");

    QMovie mov("king.gif");
    lbl.setMovie(&mov);
    lbl.resize(328, 270);
    lbl.show();
    mov.start();
    mov.setSpeed(100);

    QLabel lbl2;
    lbl2.setPixmap(QPixmap("king.gif"));
    QGraphicsColorizeEffect effect;
    effect.setColor(Qt::gray);
    lbl2.setGraphicsEffect(&effect);

    QPropertyAnimation* anim = new QPropertyAnimation(&effect, "color");

    QVariant gg;
    gg.setValue(Qt::gray);
    anim->setStartValue(gg);
     QVariant green;
    green.setValue(Qt::green);
    anim->setKeyValueAt(0.25f, green);

     QVariant red;
     red.setValue(Qt::red);
    anim->setKeyValueAt(0.5f, red);

      QVariant black;
      black.setValue(Qt::black);

    anim->setKeyValueAt(0.75f, black);
    anim->setEndValue(black);
    anim->setDuration(3000);
    anim->setLoopCount(-1);
    anim->start();
    lbl2.show();

    QLabel lbl3("Animated Window1");
    QLabel lbl4("Animated Window2");
    QPropertyAnimation* panim1 =
    new QPropertyAnimation(&lbl3, "geometry");
    panim1->setDuration(5000);
    panim1->setStartValue(QRect(120, 0, 100, 100));
    panim1->setEndValue(QRect(300, 200, 400, 400));
    panim1->setEasingCurve(QEasingCurve::InOutCirc);
    QMovie mov2("king.gif");
    lbl3.setMovie(&mov2);
    lbl3.resize(328, 270);
    lbl3.show();
    mov2.start();
    mov2.setSpeed(100);
    QPropertyAnimation* panim2 = new QPropertyAnimation(&lbl4, "pos");
    panim2->setDuration(4000);

    panim2->setStartValue(QPoint(240, 0));
    panim2->setEndValue(QPoint(240, 480));
    panim2->setEasingCurve(QEasingCurve::OutElastic);
    QParallelAnimationGroup group;
    group.addAnimation(panim2);
    group.addAnimation(panim1);
    group.setLoopCount(-1);
    group.start();

//    QStateMachine* psm = new QStateMachine;
//    QState* pStateOff = new QState(psm);
//    QRect rect1(0, 0, lbl3, lbl3.height());
//    pStateOff->assignProperty(lbl3, "geometry", rect1);
//    pStateOff->assignProperty(lbl1, "visible", true);
//    pStateOff->assignProperty(lbl2, "visible", false);
//    psm->setInitialState(pStateOff);

//    QState* pStateOn = new QState(psm);
//    QRect rect2(lbl3, 0, lbl3, lbl3.height());
//    pStateOn->assignProperty(lbl3, "geometry", rect2);
//    pStateOn->assignProperty(lbl1, "visible", false);
//    pStateOn->assignProperty(lbl2, "visible", true);
//    QSignalTransition* ptrans1 =
//    pStateOff->addTransition(lbl3, SIGNAL(clicked()), pStateOn);
//    QSignalTransition* ptrans2 =
//    pStateOn->addTransition(lbl3, SIGNAL(clicked()), pStateOff);
//    QPropertyAnimation* panim1 =
//    new QPropertyAnimation(lbl3, "geometry");
//    ptrans1->addAnimation(panim1);
//    QPropertyAnimation* panim2 =
//    new QPropertyAnimation(lbl3, "geometry");
//    ptrans2->addAnimation(panim2);


//    psm->start();


    lbl3.show();
    lbl4.show();

    return app.exec();
}
