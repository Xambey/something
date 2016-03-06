#include "menunewgame.h"

MenuNewGame::MenuNewGame(QWidget*parent): QWidget(parent)
{
    vertical = new QVBoxLayout;

    Back = new Button("&Назад");
    GameWithTwoPlayers = new Button("&2 Игрока");
    GameVsPc = new Button("&Против компьютера");

    vertical->addWidget(Back);
    vertical->addWidget(GameWithTwoPlayers);
    vertical->addWidget(GameVsPc);

    setLayout(vertical);

    setFixedSize(200,400);

}

QPushButton *MenuNewGame::GetGameWithTwoPlayersButton()
{
    return GameWithTwoPlayers;
}

QPushButton *MenuNewGame::GetGameVsPcButton()
{
    return GameVsPc;
}

QPushButton *MenuNewGame::GetBackButton()
{
    return Back;
}

