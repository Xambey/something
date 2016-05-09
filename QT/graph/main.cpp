#include <QApplication>
#include <iostream>
#include <QtGui>
#include <string>
#include "Element.h"
#include "mainwindow.h"
#include <QPalette>
#include <QtWidgets>
//#include <QDebug>
//#include <QtGui>
//#include <QWidget>
//#include <QFrame>
//#include <QScrollArea>

using namespace std;

vector<vector<Operator>> Operator::operation;
map<string, double> Operator::constant;

double 
operator_plus(double a, double b)
{
	return a + b;
}
double 
operator_minus(double a, double b)
{
	return a - b;
}

double 
operator_mult(double a, double b)
{
	return a * b;
}

double 
operator_div(double a, double b)
{
	if (b == 0)
       throw (int)(new string("Div on the NULL!"));
	return a / b;
}

double
operator_ctan(double a)
{
	return (double)1 / tan(a);
}

double 
operator_pow(double a, double b)
{
	double result = 1;
	result = pow(a, b);
	return result;
}


int main(int argc, char ** argv)
{
    QApplication app(argc, argv);
	string x;
	
	Operator::add(0, '+', operator_plus);
	Operator::add(0, '-', operator_minus);
	Operator::add(1, '/', operator_div);
	Operator::add(1, '*', operator_mult);
	Operator::add(2, '^', operator_pow);
    Operator::add(3, 'c', cos, "cos");
	Operator::add(3, 's', sin, "sin");
	Operator::add(3, 't', tan, "tg");
	Operator::add(3, 'ct', operator_ctan, "ctg");
	Operator::add(3, 'lg', log, "log");
	Operator::add(3, 'abs', abs, "abs");
	Operator::add(3, 'e', exp, "exp");

	Operator::constant.insert({ "pi", 3.14159265359 });
	Operator::constant.insert({ "e", 2.71828182846 });
    MainWindow* w = new MainWindow();

    QPixmap bkgnd("C:/Users/Andrey/Documents/QT/graph/stone.jpg");
    bkgnd = bkgnd.scaled(w->size(), Qt::KeepAspectRatioByExpanding);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    w->setPalette(palette);



    w->show();
    return app.exec();
}
