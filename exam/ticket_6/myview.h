#ifndef MYVIEW_H
#define MYVIEW_H

#include <QtWidgets>

class MyView: public QGraphicsView{
    Q_OBJECT
public:
    MyView(QGraphicsScene* pScene)
        : QGraphicsView(pScene)
    {
        (new QBasicTimer())->start(1000/30, this);
    }


protected:
    void wheelEvent(QWheelEvent*pe){
        rotate(-20);

    }
    void timerEvent(QTimerEvent *){
        rotate(-1);
        translate(-20,40);
    }

public slots:

    void updateLabel(QLabel& wgt, QPushButton* n){
        wgt.setText(n->text());
    }
signals:
    void clicked(QLineEdit&);
};

#endif // MYVIEW_H
