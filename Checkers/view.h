#ifndef VIEW_H
#define VIEW_H

#include <QtWidgets>
class View : public QGraphicsView
{
public:
    View(QGraphicsScene&);

protected:
    void showEvent(QShowEvent *event);
    void resizeEvent(QResizeEvent *event);
signals:

public slots:
};

#endif // VIEW_H
