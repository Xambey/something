#include "map.h"

MyMap::MyMap(QWidget *parent):QWidget(parent)
{
    vertical = new QVBoxLayout(this);
    grid = new QGridLayout;
    vertical->addLayout(grid);
    vertical->setSpacing(0);
    vertical->setMargin(0);

    int number(0);
    for(int i(0); i < Size; i++) {
        for(int j(0); j < Size; j++, number++) {
            grid->addWidget(new Cell(number),i,j);
        }
        number++;
    }
    grid->setMargin(0);
    grid->setSpacing(0);
    setAutoFillBackground(true);
    resize(1200,800);

    Check* check = new Check;
    grid->;

}

QVBoxLayout *MyMap::GetVboxLayout()
{
    return vertical;
}


