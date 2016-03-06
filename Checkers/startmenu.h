#ifndef STARTMENU_H
#define STARTMENU_H

#include <QtWidgets>
#include "button.h"
class StartMenu: public QWidget
{
    Q_OBJECT
public:
    explicit StartMenu(QWidget* parent = 0);
    QPushButton *GetExitFromGameButton();
    QPushButton *GetNewGameButton();
    QPushButton *GetLoadGameButton();
private:
    QVBoxLayout* vertical;
    Button* ExitFromGame;
    Button* NewGame;
    Button* LoadGame;
};

#endif // STARTMENU_H
