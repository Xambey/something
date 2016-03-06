#include "startmenu.h"

StartMenu::StartMenu(QWidget*parent): QWidget(parent)
{
    vertical = new QVBoxLayout;

    NewGame = new Button("&Новая игра");
    LoadGame = new Button("&Загрузить игру");
    ExitFromGame = new Button("&Выход");

    vertical->addWidget(NewGame);
    vertical->addWidget(LoadGame);
    vertical->addWidget(ExitFromGame);

    setLayout(vertical);

    setFixedSize(200,400);
}

QPushButton *StartMenu::GetExitFromGameButton()
{
    return ExitFromGame;
}

QPushButton *StartMenu::GetNewGameButton()
{
    return NewGame;
}

QPushButton *StartMenu::GetLoadGameButton()
{
    return LoadGame;
}

