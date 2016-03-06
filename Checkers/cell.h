#ifndef CELL_H
#define CELL_H
#include <QtWidgets>

class Cell: public QWidget
{
    Q_OBJECT
public:
    explicit Cell(int number, QWidget*parent = 0);
private:
    QPixmap pxt;
    void SetBackground();
    int Number;
protected:
    virtual void paintEvent(QPaintEvent *);
signals:

public slots:
};

#endif // CELL_H
