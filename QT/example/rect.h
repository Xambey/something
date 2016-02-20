#ifndef RECT_H
#define RECT_H

#include "base.h"
class Rect : public Base
{
public:
    Rect();
    virtual char put(){
        return 'c';
    }

};

#endif // RECT_H
