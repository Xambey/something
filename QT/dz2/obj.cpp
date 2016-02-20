#include<obj.h>

obj::obj():QObject(),m_nValue(0)
{}

void obj::slotinc()
{
    emit counterChanged(++m_nValue);

    if(m_nValue == 5) {
        emit goodbye();
    }
}
