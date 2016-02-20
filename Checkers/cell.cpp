#include "cell.h"


cell::cell(const QString &text)
{
    setText(text);


}
void cell::paintEvent(QPaintEvent *){
    QPixmap pix("mask.png");
    //setMask(pix);
    setIcon(pix);
}

