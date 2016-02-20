#include <QtWidgets>

int main (int argc, char**argv)
{
    QApplication app(argc, argv);

    QWidget wgt;
    QHBoxLayout lay;
    QLabel lbl1("I'm label widget ");
    QLabel lbl2("i'm label ");


    QStack <int> stack;
    QList <char> list;
    QString str1,str2;

    for(int i(0);i<10;i++){
        stack.push_back(i);
        str1 += QString::number(i);
    }
    lbl1.setMargin(20);
    lbl1.setText(str1);
    lbl1.setStyleSheet(
                "QLabel{"
                "border-style: solid;"
                "border-width: 6px;"
                "border-color: yellow;"
                "color: green;"
                "}"
                );
    for(char i('A');i <= 'Z';i++){
        list.push_back(i);
        str2 += QString(i);
    }
    lbl2.setStyleSheet(
                "QLabel{"
                "border-style: solid;"
                "border-width: 10px;"
                "border-color: green;"
                "color: red;"
                "}"
                );
    lbl2.setText(str2);
    lay.addWidget(&lbl1);
    lay.addWidget(&lbl2);
    lay.setSpacing(20);
    wgt.setLayout(&lay);
    wgt.show();
    return app.exec();
}
