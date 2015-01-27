#include "Holiday.h"  

Holiday::Holiday()
{
    enabled = false;
    
    
}

Holiday::Holiday(int timeGroup, int mst, int lst)
{
    enabled = true;
    this->timeGroup = timeGroup;
    this->MST = mst;
    this->LST = lst;
}

