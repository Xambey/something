#ifndef view
#define view

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>

class View : public QWidget
{
    Q_OBJECT

public:
    View(QWidget *parent);
    QPainterPath path;
    QPoint pos;
public slots:
    void setBrush(const QBrush &brush);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent * event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent * event) Q_DECL_OVERRIDE;
    void wheelEvent(QWheelEvent * event) Q_DECL_OVERRIDE;
private:
    QBrush brush;
    QPoint dragStart;
    double zoom;
    bool dragEnable;
};
#endif

