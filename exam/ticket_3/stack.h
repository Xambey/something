#ifndef STACK
#define STACK
#include <QtWidgets>
class stack: public QStackedWidget

{
    Q_OBJECT
public:
    stack(){
        value = 1;
    }
private:
    int value;
public slots:
    void setNowIndex(bool){
        if(value){
            setCurrentIndex(value - 1);
            value = 0;
            this->update();
        }else{
            setCurrentIndex(value + 1);
            value = 1;
            this->update();
        }
    }
};
#endif // STACK

