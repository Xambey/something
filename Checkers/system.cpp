#include "system.h"
System::System(QWidget*parent): QGraphicsScene(parent)
{
        setSceneRect(0,0,1200,800);
        View* view = new View(*this);
        menu = new Menu(this); //qwidget menu
        view->resize(QSize(menu->GetSizeMenu().width(),menu->GetSizeMenu().height())); // set size view = size picture(background) of menu

        addWidget(menu);
        view->show();
        QObject::connect(menu->GetButtonForExit(),SIGNAL(clicked(bool)),view,SLOT(close()));
//        QObject::connect(menu->GetButtonForGameWithTwoPlayers(),SIGNAL(clicked(bool)),this,SLOT(deleteLater()));
}

