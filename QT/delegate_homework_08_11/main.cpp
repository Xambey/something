#include <QLabel>
#include <QtGui>
#include <QApplication>
#include <QSplitter>
#include <QTextEdit>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QCheckBox>
#include <QGroupBox>
#include<QRadioButton>
#include <QWidget>
#include <QGridLayout>
#include <QAbstractSlider>
#include <QDial>
#include <QSlider>
#include <cstdlib>
#include <ctime>
#include <QWidget>
#include <QSyntaxHighlighter>
#include <QtGui>
#include <QComboBox>
#include <QStringList>
#include <QTableWidget>
#include <QToolBox>
#include <QVariant>
#include <QAbstractItemModel>
#include <QTreeView>
#include <QListView>
#include <QItemDelegate>
#include <iostream>
#include <QStandardItemModel>
#include "mydelegate.h"

    /*разработать собственную модель, содержание определить самим(цвета, работа со слоями ролью, применять какие-нибудь делегаты*/

int main(int argc, char** argv){
    QApplication app(argc, argv);
    QStandardItemModel model(2, 3);
    QStringList str;
    str << "edit 1" << "edit2" << "edit3" << "edit 4" << "edit5" << "edit6";

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 3; j++){
            QModelIndex index = model.index(i, j);
            model.setData(index, str[j]);
        }
    //    QStandardItemModel model(3, 4);
//    QStringList on;
//    on << "1" << "2" << "3";
//    QStringList str21;
//    str21 << "item1";
//    model.setHorizontalHeaderLabels(QStringList() <<""<< "Дата" << "телефон" << "Имя");
//    for(int top_row = 0; top_row < 3;top_row++){
//        QModelIndex index1 = model.index(top_row, 0);
//        QString str1 = QString("ivb-3-1"+QString::number(top_row+3));
//        model.setData(index1, str1);
//        model.insertRows(0, 3, index1);
//        model.insertColumns(0, 1, index1);
//        for(int row = 0; row < 3; row++){
//            QModelIndex index2 = model.index(row, 0, index1);
//            QString str2 = QString("student"+QString::number(row+1));
//            model.setData(index2, str2);
//            model.insertRows(0, 1, index2);
//            model.insertColumns(0, 3, index2);
//            for(int ro = 0; ro < 3; ++ro){
//                QModelIndex index3 = model.index(0, ro, index2);
//                model.setData(index3, str21[ro]+QString::number(row+1));
//            }
//        }
//    }



    QTableView treeView;
    //treeView.setItemDelegate(new SpinBoxDelegate(&treeView));
    treeView.setModel(&model);
    treeView.setItemDelegate(new myDelegate(&treeView));
    treeView.resize(600,600);
    treeView.viewport()->setAttribute(Qt::WA_Hover);
    treeView.show();
    return app.exec();
}
