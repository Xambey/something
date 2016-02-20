#include "button.h"

#define HeightButton 80
#define WidthButton 60
Button::~Button(){}

Button::Button(QString name):QPushButton(name){
    setAutoFillBackground(true);
    setFixedHeight(HeightButton);
    setFixedWidth(WidthButton);
    setStyleSheet( "QPushButton"
                                    "{"
                                        "background-color: rgb(150, 200, 0);"
                                        "border-style: inset;"
                                        "color: red;"
                                        "border-style: outset;"
                                        "border-width: 0px;"
                                        "border-radius: 10px;"
                                        "border-color: beige;"
                                        "font: bold 14p;"
                                        "min-width: 10em;"
                                        "padding: 0px;"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                        "background-color: rgb(224, 200, 0);"
                                        "border-style: inset;"
                                        "color: red;"
                                        "border-style: outset;"
                                        "border-width: 0px;"
                                        "border-radius: 10px;"
                                        "border-color: beige;"
                                        "font: bold 14p;"
                                        "min-width: 10em;"
                                        "padding: 0px;"
                                    "}"
                                    "QPushButton:pressed"
                                    "{"
                                        "background-color: rgb(224, 200, 100);"
                                        "border-style: inset;"
                                        "color: red;"
                                        "border-style: outset;"
                                        "border-width: 0px;"
                                        "border-radius: 10px;"
                                        "border-color: beige;"
                                        "font: bold 14p;"
                                        "min-width: 10em;"
                                        "padding: 0px;"
                                    "}");
}

