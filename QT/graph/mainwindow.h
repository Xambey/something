#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

class View;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_pushButton_clicked();

    void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);

   //void on_plainTextEdit_textChanged();

private:
    Ui::MainWindow *ui;
    View *area;
};

#endif // MAINWINDOW_H
