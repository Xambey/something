#ifndef MENU_H
#define MENU_H

#include <QtWidgets>
#include <button.h>

class Menu: public QWidget
{
    Q_OBJECT
private:
    QGraphicsScene* scene;
    QPixmap pxt;
    QVBoxLayout* vertical_0;
    QVBoxLayout* vertical_1;
    QVBoxLayout* vertical_2;
    QHBoxLayout* horizontal;

    QMovie* mov;

    //buttons
    Button* ExitFromGame;
    Button* NewGame;
    Button* LoadGame;
    Button* GameWithTwoPlayers;
    Button* GameVsPc;
    void SetPalette();

public:
    Menu(QGraphicsScene* scene);
    QSize GetSizeMenu();
    QPushButton* GetButtonForExit();
    QPushButton* GetButtonForNewGame();
    QMovie* GetMovie();
public slots:
    void GameModeSelection(bool);
};

#endif // MENU_H
