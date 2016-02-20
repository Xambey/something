#ifndef OBJ_H
#define OBJ_H

#include <QObject>

class obj:public QObject
{
    Q_OBJECT
private:
    int m_nValue;
public:
    obj();
signals:
    void goodbye();
    void counterChanged(int);
public slots:
    void slotinc();
};

#endif // OBJ_H
