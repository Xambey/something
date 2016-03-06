#ifndef BUTTON_H
#define BUTTON_H
#include <QtWidgets>

class Button: public QPushButton/*, public QGraphicsItem*/
{
public:
    explicit Button(QWidget* parent = 0);
    Button(QString);
    ~Button();
signals:

public slots:
};

#endif // BUTTON_H
