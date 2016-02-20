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
#include <QProgressBar>
#include <QGraphicsProxyWidget>



int main (int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget a;
    QWidget wgt;
    QWidget b;
    QHBoxLayout ha;
    QVBoxLayout va;
    QWidget c;

    QPalette pal;
    pal.setBrush(QPalette::Background, Qt::red);
    a.setAutoFillBackground(true);
    a.resize(100,100);
    a.setPalette(pal);
    QPalette pal1;
    pal.setBrush(QPalette::Background, Qt::green);
    b.setAutoFillBackground(true);
    b.resize(100,100);
    b.setPalette(pal1);
    QPalette pal2;
    pal2.setBrush(QPalette::Background, Qt::blue);
    c.resize(100,100);
    c.setAutoFillBackground(true);
    c.setPalette(pal2);

    wgt.resize(1000,1000);
    ha.addWidget(&a);
    ha.addWidget(&b);
    va.addWidget(&c);
    ha.addLayout(&va);
    wgt.setLayout(&ha);
    wgt.show();
    return app.exec();
}
