#include <QtWidgets>
#include "menu.h"

#define TwoPlayers 1
#define GameVsPc 2

Menu::Menu(QGraphicsScene*scene)
{
    this->scene = scene;
    SetBackground();

    horizontal = new QHBoxLayout;
    vertical = new QVBoxLayout;

    startMenu = new StartMenu;
    menuNewGame = new MenuNewGame;
    gameWithTwoPlayers = NULL;

    vertical->addWidget(startMenu);

    vertical->setMargin(0);
    vertical->setSpacing(0);
    horizontal->setMargin(0);
    horizontal->setSpacing(0);

    horizontal->addLayout(vertical);

    horizontal->setAlignment(vertical,Qt::AlignRight);

//all connections
    QObject::connect(startMenu->GetNewGameButton(),SIGNAL(clicked(bool)),this,SLOT(PressedNewGameButton(bool)));
    QObject::connect(menuNewGame->GetBackButton(),SIGNAL(clicked(bool)),this,SLOT(PressedBackButton(bool)));
    QObject::connect(menuNewGame->GetGameWithTwoPlayersButton(),SIGNAL(clicked(bool)),this,SLOT(StartGameWithTwoPlayers(bool)));

    setLayout(horizontal);
    startMenu->show();
}

void Menu::SetBackground()
{
    pxt.load("background.png");
    QPalette pal;
    pal.setBrush(backgroundRole(),pxt);
    setPalette(pal);
    resize(1200,800);
    setAutoFillBackground(true);
}

Menu::Menu(QWidget *parent): QWidget(parent)
{
}

QSize Menu::GetSizeMenu()
{
    return pxt.size();
}

QPushButton *Menu::GetButtonForExit()
{
    return startMenu->GetExitFromGameButton();
}

QPushButton *Menu::GetButtonForGameWithTwoPlayers()
{
    return menuNewGame->GetGameWithTwoPlayersButton();
}

void Menu::PressedNewGameButton(bool)
{
    //Не трогать! Древняя магия
    startMenu->hide();
    vertical->removeWidget(startMenu);


    vertical->addWidget(menuNewGame);
    menuNewGame->show();
}

void Menu::PressedBackButton(bool)
{
    //Не трогать! Древняя магия

    menuNewGame->hide();

    vertical->removeWidget(menuNewGame);

    vertical->addWidget(startMenu);
    startMenu->show();
}

void Menu::StartGameWithTwoPlayers(bool)
{
    scene->removeItem(this);
    gameWithTwoPlayers = new GameWithTwoPlayers(scene);
}



