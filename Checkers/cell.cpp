#include "cell.h"


Cell::Cell(int number, QWidget *parent): QWidget(parent),Number(number)
{
    SetBackground();
}

void Cell::SetBackground()
{
    if(Number % 2){
        pxt.load("yellow.png");
        QPalette pal;
        pal.setBrush(backgroundRole(),pxt);
        setPalette(pal);
        resize(150,100);
        setAutoFillBackground(true);
    }
    else {
        pxt.load("black.png");
        QPalette pal;
        pal.setBrush(backgroundRole(),pxt);
        setPalette(pal);
        resize(150,100);
        setAutoFillBackground(true);
    }

}

void Cell::paintEvent(QPaintEvent *){
    QPixmap pix("mask.png");
    //setMask(pix);
    //setIcon(pix);
}

