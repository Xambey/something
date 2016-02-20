#include "map.h"

MyMap::MyMap(QWidget *parent):QWidget(parent)
{
    QGridLayout* layout = new QGridLayout(parent);
    int j = 0,k = 0;
    char f = true;
    for(int i(0); i < 64; i++,k++) {
        cell* button = new cell(QString::number(i+1));
        if(f){
//            QPixmap pix("yellow.png");
//            QPalette pal;
//            pal.setBrush(button->backgroundRole(),QBrush(pix));
//            button->setPalette(pal);
            button->setAutoFillBackground(true);
        }/* else{
            QPixmap pix("yellow.png");
            QPalette pal;
            pal.setBrush(button->backgroundRole(),QBrush(pix));
            button->setPalette(pal);
        }*/

        layout->addWidget(button,j,k);

        if(k == 7){
            j++;
            k = -1;
        }
    }
    parent->setLayout(layout);

}


