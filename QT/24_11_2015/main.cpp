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
#include"keyfilter.h"
#include "mypainter.h"

void mousePress(QWidget* pwgt,
                int x,
                int y,
                Qt::MouseButton bt = Qt::LeftButton,
                Qt::MouseButtons bts = Qt::LeftButton
)
{
    if (pwgt) {
        QMouseEvent* pePress =
        new QMouseEvent(QEvent::MouseButtonPress,QPoint(x, y),bt,bts,Qt::NoModifier);
        QApplication::postEvent(pwgt, pePress);
    }
}

int main (int argc, char** argv)
{
    QApplication app (argc, argv);
    Myline txt("User input: ");
    txt.show();
    txt.resize(280, 20);
    int i;
    for (i = 0; i < Qt::Key_Z - Qt::Key_A + 1; ++i) {
        QChar ch = 65 + i;
        int nKey = Qt::Key_A + i;
        QKeyEvent* pePress = new QKeyEvent(QEvent::KeyPress, nKey, Qt::NoModifier, ch);
        QApplication::sendEvent(&txt, pePress);
        QKeyEvent* peRelease = new QKeyEvent(QEvent::KeyRelease, nKey, Qt::NoModifier, ch);
        QApplication::sendEvent(&txt, peRelease);
        QApplication::sendEvent(&txt, new QMouseEvent(QEvent::MouseButtonPress, QPoint(120,10), Qt::LeftButton,Qt::LeftButton, Qt::NoModifier));
        QApplication::sendEvent(&txt, new QMouseEvent(QEvent::MouseButtonRelease, QPoint(120,10), Qt::LeftButton,Qt::LeftButton, Qt::NoModifier));
    }
    KeyFilter* pFilter = new KeyFilter(&txt);
    txt.installEventFilter(pFilter);

    MyPainter pa;
    pa.resize(500, 500);
    pa.show();
    return app.exec();
}

