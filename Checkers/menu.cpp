#include <QtWidgets>
#include "menu.h"


#define HeightButton 80
#define WidthButton 60

Menu::Menu(QGraphicsScene*scene):vertical_2(0)
{
    this->scene = scene;
    SetPalette();

    horizontal = new QHBoxLayout;
    vertical_1 = new QVBoxLayout;
    vertical_0 = new QVBoxLayout;

    QLabel *lbl = new QLabel;

    vertical_0->setMargin(0);
    vertical_0->setSpacing(10);

    mov = new QMovie("giphy.gif");

    lbl->setMovie(mov);
    lbl->resize(700, 700);


    vertical_0->addWidget(lbl);





    NewGame = new Button("&Новая игра");
    LoadGame = new Button("&Загрузить игру");
    ExitFromGame = new Button("&Выход");

    vertical_1->setMargin(5);
    vertical_1->setSpacing(10);



    vertical_1->addWidget(NewGame);
    vertical_1->addWidget(LoadGame);
    vertical_1->addWidget(ExitFromGame);

    horizontal->addLayout(vertical_0);
    horizontal->addLayout(vertical_1);

    horizontal->setAlignment(vertical_0,Qt::AlignHCenter);

    setLayout(horizontal);
}

void Menu::SetPalette()
{
    pxt.load("background.png");
    QPalette pal;
    pal.setBrush(backgroundRole(),pxt);
    setPalette(pal);
    resize(1200,800);
    autoFillBackground();
}

QSize Menu::GetSizeMenu()
{
    return pxt.size();
}

QPushButton *Menu::GetButtonForExit()
{
    return ExitFromGame;
}

QPushButton *Menu::GetButtonForNewGame()
{
    return NewGame;
}

QMovie *Menu::GetMovie()
{
    return mov;
}

void Menu::GameModeSelection(bool)
{   

    if(vertical_2 == NULL){
        vertical_2 = new QVBoxLayout;
        scene->update();

        GameWithTwoPlayers = new Button("2 Игрока");
        GameVsPc = new Button("Против компьютера");

        vertical_2->setAlignment(GameWithTwoPlayers,Qt::AlignCenter);
        vertical_2->setAlignment(GameVsPc,Qt::AlignCenter);


        vertical_2->addWidget(GameWithTwoPlayers);
        vertical_2->addWidget(GameVsPc);
        horizontal->addLayout(vertical_2);
    }
    else{
        GameWithTwoPlayers->~Button();
        GameVsPc->~Button();
        vertical_2->~QVBoxLayout();
        vertical_2 = NULL;
    }

}



