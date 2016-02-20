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


#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "proxy.h"
#include "pult.h"
#include "progress.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    scene.setStickyFocus(true);
#ifndef Q_OS_WINCE
    const int gridSize = 10;
#else
    const int gridSize = 5;
#endif

    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            proxy *gg= new proxy(0, Qt::Window);
            gg->setWidget(new pult);

            QRectF rect = gg->boundingRect();

            gg->setPos(x * rect.width() * 1.05, y * rect.height() * 1.05);
            gg->setCacheMode(QGraphicsItem::DeviceCoordinateCache);

            scene.addItem(gg);
        }
    }
    scene.setSceneRect(scene.itemsBoundingRect());

    QGraphicsView view(&scene);
    view.scale(0.5, 0.5);
    view.setRenderHints(view.renderHints() | QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.show();
    view.setWindowTitle("Example text, write something please");
    return app.exec();
}
