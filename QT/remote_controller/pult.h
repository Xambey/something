#ifndef PULT_H
#define PULT_H

#include <QLabel>
#include <QtGui>
#include <QApplication>
#include <QSplitter>
#include <QTextEdit>
#include <QLineEdit>
#include <QSpinBox>
#include "progress.h"
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
#include <QBrush>
#include <QProgressBar>

#include <QDialog>

class pult: public QWidget
{
    Q_OBJECT
public:
    pult();

signals:

public slots:
};

#endif // PULT_H
