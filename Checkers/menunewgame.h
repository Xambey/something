#ifndef MENUNEWGAME_H
#define MENUNEWGAME_H

#include <QtWidgets>
#include "button.h"
class MenuNewGame: public QWidget
{
    Q_OBJECT
public:
    explicit MenuNewGame(QWidget* parent = 0);
    QPushButton *GetGameWithTwoPlayersButton();
    QPushButton *GetGameVsPcButton();
    QPushButton *GetBackButton();
private:
    QVBoxLayout* vertical;
    Button* GameWithTwoPlayers;
    Button* GameVsPc;
    Button* Back;
};

#endif // MENUNEWGAME_H
