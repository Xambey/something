#ifndef CELL_H
#define CELL_H
#include <QtWidgets>

class cell: public QPushButton
{
public:
    cell(const QString &text);
protected:
    virtual void paintEvent(QPaintEvent *);
signals:

public slots:
};

#endif // CELL_H
