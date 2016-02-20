#include "formmenu.h"
#include "ui_formmenu.h"

FormMenu::FormMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormMenu)
{
    ui->setupUi(this);
}

FormMenu::~FormMenu()
{
    delete ui;
}

void FormMenu::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
