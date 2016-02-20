#ifndef _KeyFilter_h_
#define _KeyFilter_h_
#include <QtGui>
// ======================================================================
class KeyFilter : public QObject {
    protected:
        bool eventFilter(QObject* pobj, QEvent* pe)
        {
        if (pe->type() == QEvent::KeyPress) {
            if (((QKeyEvent*)pe)->key() == Qt::Key_Z) {
                QKeyEvent* pe = new QKeyEvent(QEvent::KeyPress,
                Qt::Key_Escape,
                Qt::NoModifier,
                "П"
                );
                QApplication::sendEvent(pobj, pe);
                return true;
            }
            if (((QKeyEvent*)pe)->key() == Qt::Key_G) {
                QKeyEvent* pe = new QKeyEvent(QEvent::KeyPress,
                Qt::Key_Escape,
                Qt::NoModifier,
                "И"
                );
                QApplication::sendEvent(pobj, pe);
                return true;
            }
            if (((QKeyEvent*)pe)->key() == Qt::Key_M) {
                QKeyEvent* pe = new QKeyEvent(QEvent::KeyPress,
                Qt::Key_Escape,
                Qt::NoModifier,
                "Н"
                );
                QApplication::sendEvent(pobj, pe);
                return true;
            }
        }
        else
            return false;
        }
    public:
        KeyFilter(QObject* pobj = 0)
        : QObject(pobj)
        {
        }
    };
#endif //_KeyFilter_h_
