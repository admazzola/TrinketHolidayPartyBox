#ifndef Holiday_h
#define Holiday_h

#include "Arduino.h"
 const int MAX_ANIM_COUNT = 24;

class Holiday {
  
   private:
    boolean enabled;
    int timeGroup;  //yearly or daily    
    int MST;  //most significant time.. either be the month or the hour (depends on timegroup)
    int LST;  //least signifiact time... either the day of the month or the minute (depends on timegroup)
    int numColors;
    int counter;  //animation counter
    uint32_t colorSwatches[3];
   
   
    static const int SIZE = 10;      // initial size of the array
    int *Items;                      // Items will point to the dynamically allocated array
    int numItems;                    // number of items currently in the list
    int arraySize;                   // the current size of the array
    
    
  public:
    Holiday(int timeGroup, int mst, int lst, uint32_t colorOne);
    Holiday(int timeGroup, int mst, int lst, uint32_t colorOne, uint32_t colorTwo);
    Holiday(int timeGroup, int mst, int lst, uint32_t colorOne, uint32_t colorTwo, uint32_t colorThree);

   Holiday();
    boolean isActive();              // add k to the end of the list
    void getPixelColors(int pixelIndex, int rgb[3]);
 
};
#endif
