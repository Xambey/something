#include <QtWidgets>
#include "mylabel.h"
int main(int argc,char**argv)
{
    QApplication app(argc, argv);
    QLineEdit edit;
    QLabel lbl("I'm a label");
    QProgressBar bar;
    QSpinBox spinbox;
    QLCDNumber lcd;
    Myline lbl2;
    lcd.setFixedHeight(40);

    QWidget wgt;
    lcd.setSegmentStyle(QLCDNumber::Filled);
    lcd.setMode(QLCDNumber::Hex);
    spinbox.setFixedHeight(30);


    QObject::connect(&spinbox, SIGNAL(valueChanged(int)),&lcd, SLOT(display(int)));
    QObject::connect(&spinbox, SIGNAL(valueChanged(QString)),&lbl,SLOT(setText(QString)));
    QObject::connect(&spinbox, SIGNAL(valueChanged(QString)),&lbl2,SLOT(setText(QString)));
    QObject::connect(&spinbox, SIGNAL(valueChanged(int)),&bar, SLOT(setValue(int)));
    QObject::connect(&edit, SIGNAL(textChanged(QString)),&lbl2, SLOT(setText(QString)));
    lbl.setStyleSheet(
                "QLabel{"
                "font-size: 20pt;"
                "color: red;"
                "}");
    lbl2.setStyleSheet(
                "QLabel{"
                "font-size: 25pt;"
                "color: green;"
                "}");

    QVBoxLayout* lay = new QVBoxLayout;
    lay->addWidget(&lcd);
    lay->addWidget(&lbl);
    lay->addWidget(&lbl2);
    lay->addWidget(&bar);
    lay->addWidget(&spinbox);
    lay->addWidget(&edit);

    wgt.setLayout(lay);
    wgt.resize(250, 150);
    wgt.show();

    return app.exec();
}
