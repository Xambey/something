#include <Qtwidgets>

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

    QMovie mov("deadline.gif");
    lbl.setMovie(&mov);
    lbl.resize(328, 270);
    lbl.show();
    mov.start();
    mov.setSpeed(100);

    QLabel lbl2;
    lbl2.setPixmap(QPixmap("deadline.gif"));
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
    QVariant red;     red.setValue(Qt::red);
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

    QMovie mov2("deadline.gif");
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

    lbl3.show();
    lbl4.show();

    return app.exec();
}

