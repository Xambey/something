#include "system.h"
System::System()
{
        View* view = new View(*this);
        menu = new Menu(this); //qwidget menu
        QObject::connect(menu->GetButtonForExit(),SIGNAL(clicked(bool)),view,SLOT(close()));
        QObject::connect(menu->GetButtonForNewGame(),SIGNAL(clicked(bool)),menu,SLOT(GameModeSelection(bool)));

        view->resize(QSize(menu->GetSizeMenu().width(),menu->GetSizeMenu().height())); // set size view = size picture(background) of menu

        addWidget(menu);
        view->show();
        menu->GetMovie()->start();

}

