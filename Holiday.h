#ifndef Holiday_h
#define Holiday_h

#include "Arduino.h"


class Holiday {
  
   private:
    boolean enabled;
    int timeGroup;  //yearly or daily    
    int MST;  //most significant time.. either be the month or the hour (depends on timegroup)
    int LST;  //least signifiact time... either the day of the month or the minute (depends on timegroup)
    
   
    static const int SIZE = 10;      // initial size of the array
    int *Items;                      // Items will point to the dynamically allocated array
    int numItems;                    // number of items currently in the list
    int arraySize;                   // the current size of the array
    
    
  public:
    Holiday(int timeGroup, int mst, int lst);
   Holiday();
    void isActive(int k);              // add k to the end of the list
   
 
};
#endif
