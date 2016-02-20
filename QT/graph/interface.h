#ifndef INTERFACE
#define INTERFACE

#include <QObject>
#include <vector>
using namespace std;

class interface:public QObject{
    Q_OBJECT
    interface(vector <double>);
public slots:
    void changed();
};

#endif // INTERFACE

