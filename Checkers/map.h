#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "cell.h"
#include "check.h"

#define Size 8
#define CountCells 64

class MyMap : public QWidget
{
    Q_OBJECT
public:
    explicit MyMap(QWidget *parent = 0);
    QVBoxLayout *GetVboxLayout();
private:
    QGridLayout* grid;
    QVBoxLayout* vertical;
};

#endif // MAP_H
