#ifndef MYGRADIENT_H
#define MYGRADIENT_H
#include <QtWidgets>
#include <Qwidget>

class QPaintEvent;
class MyGradient : public QWidget
{
     Q_OBJECT
public:
   MyGradient(QWidget* parent = 0);
   ~MyGradient();
protected:
    void paintEvent(QPaintEvent *);
};

#endif // MYGRADIENT_H
