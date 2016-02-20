#include <QtWidgets>

#include "stack.h"



int main(int argc, char**argv)
{
    QApplication app(argc, argv);

    stack mystack;
    QPushButton lbl1("I'm first widget");
    QPushButton lbl2("I'm the second widget");

    mystack.setFrameStyle(QFrame::VLine | QFrame::Sunken);
    mystack.setStyleSheet(
                "QStackedWidget{"
                "border-style: solid;"
                "border-width: 10px;"
                "border-radius: 20px;"
                "border-color: green;"
                "}"
                );
    mystack.resize(200,200);
    mystack.addWidget(&lbl2);
    mystack.addWidget(&lbl1);

    QObject::connect(&lbl1,SIGNAL(clicked(bool)),&mystack,SLOT(setNowIndex(bool)));
    QObject::connect(&lbl2,SIGNAL(clicked(bool)),&mystack,SLOT(setNowIndex(bool)));
    mystack.show();
    return app.exec();
}

