#ifndef CHECK_H
#define CHECK_H

#include <QWidget>
#include <QtWidgets>

class Check : public QWidget
{
    Q_OBJECT
public:
    explicit Check(QWidget *parent = 0);
private:
    void SetBackground();
signals:

public slots:
};

#endif // CHECK_H
