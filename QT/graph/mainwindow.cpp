#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Element.h"
#include "Operator.h"
#include <QDebug>
#include <QString>
#include "view.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    area = new View(0);
    ui->scrollArea->setWidget(area);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_clicked()
{
//    Element A(Operator::format(ui->plainTextEdit->toPlainText().toStdString()));
//    try
//        {
//            string x;
//            while (true){
//                //cout << "Enter to your function: \n";
//                //getline(cin, x);
//                x = ui->plainTextEdit->toPlainText().toStdString();
//                if (x != "quit")
//                {
//                    Element* root = new Element(Operator::format(x));
//                    vector<double> result;
//                    double y;
//                    for (double i = 0; i < 30; i += 0.5)
//                    {
//                        double r = root->operator()(i);
//                        result.push_back(r);
//                        //std::cout << r << ' ';
//                    }
//                    delete root;
//                    //cout << endl << system("pause") << endl;;
//                }
//                else
//                    return;
//            }
//        } catch(...)
//        {
//            //cout << endl << "unknown simbol";
//            //system("pause");
//        }
    //#b7b82b
    // scene->setSceneRect(900, 0, -900, 0);
 //                QPalette pal;
 //                pal.setBrush(ui->centralwidget->backgroundRole(), QBrush(QPixmap("stone.jpg")));
 //                ui->centralwidget->setPalette(pal);
     //должно работать же ... мб камень неподъемный?
     //scene->setMinimumRenderSize(60);
/*
    QString col = "#b7b82b";
    QPalette pal3;
    QColor c("#b7b82b");

    pal3.setBrush(QPalette::Background, c );
    ui->plainTextEdit->setPalette( pal3 );

    QPainter painter(this);
    painter.setPen(palette().dark().color());
    painter.setBrush(QBrush(Qt::red));
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.save();
*/
    string s = "quit";
    string ndata = ui->plainTextEdit->toPlainText().toStdString();
    if(ndata != s)
    {
        QPainterPath path;
        area->path.swap(path);
        double start = area->pos.x()- area->width();
        double end = area->pos.x();
        Element* root = new Element(Operator::format(ndata));

        double step = ui->plainTextEdit_2->toPlainText().toDouble();

        area->path.moveTo(start, root->operator()(start));
        for (double x = start; x < end; x += step)
        {
            area->path.lineTo(x,root->operator()(x));
        }
        area->update();
        delete root;
    }else
        close();
}


void MainWindow::on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint)
{
//    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);

//    QPen pen(Qt::green);
//    scene->addLine(0,90,180,90,pen);//x
//    scene->addLine(90,0,90,180,pen);//y

//    ui->graphicsView->setScene(scene);
//    //ui->graphicsView->setBackgroundBrush(white);
//    //ui->graphicsView->
}


