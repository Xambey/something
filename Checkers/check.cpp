#include "check.h"

Check::Check(QWidget *parent) : QWidget(parent)
{
    SetBackground();
}

void Check::SetBackground()
{
        QPixmap pxt;
        pxt.load("black_check.png");
        QPalette pal;
        pal.setBrush(backgroundRole(),pxt);
        setPalette(pal);
        resize(81,79);
        setMask(pxt.mask());
        setAutoFillBackground(true);
}

