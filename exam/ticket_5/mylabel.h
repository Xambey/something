#ifndef MYLABEL_H
#define MYLABEL_H

#include <QtWidgets>
class Myline : public QLineEdit
{
    Q_OBJECT
public:
    Myline(){}
protected:
    virtual void keyPressEvent(QKeyEvent*p){
        switch (p->key()) {
            case Qt::Key_9:
            {
                this->setText("I understand only 9 number and replace it on this text");
                break;
            }
            case Qt::Key_8:
            {
                this->setText("You press 8");
                break;
            }
            case Qt::Key_Backspace:
            {
                int length = this->text().length() - 1;
                QString strdel;
                strdel = this->text().left(length);
                this->setText(strdel);
                break;
            }
            default:
            {
                QString str(this->text() + p->text());
                this->setText(str);
                QWidget::keyPressEvent(p);
            }
        }
    }
};

#endif // MYLABEL_H
