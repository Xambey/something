#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "cell.h"

class MyMap : public QWidget
{
    Q_OBJECT
public:
    explicit MyMap(QWidget *parent = 0);
signals:

public slots:
};

#endif // MAP_H
