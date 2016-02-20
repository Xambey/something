#include <QtWidgets>


int main(int argc, char**argv)
{
    QApplication app(argc,argv);
    QStandardItemModel model(5,3);
    QTreeView *table = new QTreeView;
    table->setModel(&model);

    model.setHorizontalHeaderLabels(QStringList() << "Обед" << "еда" << "имя");
    QStringList name;
    name << "Ильдар" << "Рим" << "Миша" << "Саша";
    QStringList year;
    year << "1997" << "1997" << "1996" << "1997";
    for (int nTopRow = 0; nTopRow < 5; ++nTopRow) {
        QModelIndex index = model.index(nTopRow, 0);
        model.setData(index, "Обед " + QString::number(nTopRow + 1));
        model.insertRows(0, 4, index);
        model.insertColumns(0, 1, index);
        for (int a = 0; a < 4; ++a) {
            QModelIndex index2 = model.index(a, 0, index);
            model.setData(index2, "ДошИрак" + QString::number(a + 1));
            model.insertRows(0, 4, index2);
            model.insertColumns(0, 2, index2);
            for (int b = 0; b < 4; ++b) {
                model.setData(model.index(b, 0, index2),name [b]);
                model.setData(model.index(b, 1, index2),year [b]);
//                model.setData(model.index(b, 3, index2),);
            }
        }
    }

    table->resize(400,400);
    table->show();


    QWidget wgt;
    QLabel* lbl = new QLabel("0");
    lbl->setStyleSheet(
                "QLabel{"
                "font-size: 25pt;"
                "color: green;"
                "}");
    QScrollBar* menu = new QScrollBar(Qt::Horizontal);

    QObject::connect(menu, SIGNAL(valueChanged(int)),lbl, SLOT(setNum(int)));

    QVBoxLayout* lay = new QVBoxLayout;
    lay->addWidget(lbl);
    lay->addWidget(menu);
    wgt.setLayout(lay);

    wgt.resize(60, 60);
    wgt.show();
    return app.exec();
}
