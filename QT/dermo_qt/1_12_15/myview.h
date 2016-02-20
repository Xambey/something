#ifndef MYVIEW_H
#define MYVIEW_H
#include <QGraphicsView>
#include <QWheelEvent>
#include <QTimerEvent>
#include <QBasicTimer>
#include <QWidget>
#include <QLineEdit>
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
