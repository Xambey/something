#ifndef MENU_H
#define MENU_H

#include <QtWidgets>
#include "startmenu.h"
#include "menunewgame.h"
#include "gamewithtwoplayers.h"

class Menu: public QWidget, public QGraphicsItem
{
    Q_OBJECT
private:
    GameWithTwoPlayers* gameWithTwoPlayers;
    QGraphicsScene* scene;
    QPixmap pxt;

    QHBoxLayout* horizontal;

    StartMenu* startMenu;
    MenuNewGame* menuNewGame;

    QVBoxLayout* vertical;
    void SetBackground();

public:
    explicit Menu(QWidget* parent = 0);
    Menu(QGraphicsScene* scene);
    virtual void paint(QPainter*,const QStyleOptionGraphicsItem*,QWidget*){}

    virtual QRectF boundingRect() const{QRectF f;return f;}
    QSize GetSizeMenu();
    QPushButton* GetButtonForExit();
    QPushButton* GetButtonForGameWithTwoPlayers();

public slots:
    void PressedNewGameButton(bool);
    void PressedBackButton(bool);
    void StartGameWithTwoPlayers(bool);
};

#endif // MENU_H
