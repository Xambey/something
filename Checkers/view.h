#ifndef VIEW_H
#define VIEW_H

#include <QtWidgets>
class View : public QGraphicsView
{
public:
    explicit View(QWidget*parent = 0);
    View(QGraphicsScene&);

protected:
    void showEvent(QShowEvent *event);
    void resizeEvent(QResizeEvent *event);
signals:

public slots:
};

#endif // VIEW_H
