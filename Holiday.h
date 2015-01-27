#ifndef Holiday_h
#define Holiday_h

#include "Arduino.h"

 
 
 //these are the types of 'holidays'.  Daily or Yearly.
const unsigned int DAILY = 0;  //ints are for hour and min
const unsigned int YEARLY = 1;  //ints are for month and numeric day of the month (15th, 20th,..)
const unsigned int YEARLY_DAYDEPENDANT = 2;  //christmas, thanksgiving... ints are for the month, the week of the month, and the day of the week (mon/tues...)
const unsigned int EASTER_OFFSET = 3; //only 1 int, the offset from easter (0 is for easter)

const unsigned int ELEVEN_ELEVEN_AM = 0;
const unsigned int ELEVEN_ELEVEN_PM = 1;
const unsigned int ANNIVERSARY = 2;
const unsigned int BIRTHDAY = 3;
const unsigned int JULY_FOUR = 4;
const unsigned int CHRISTMAS = 5;
const unsigned int NEWYEARS = 6;  
const unsigned int THANKSGIVING = 7;  //fourth thursday of november
const unsigned int HALLOWEEN = 8;
const unsigned int LEIF_ERIKSON_DAY = 9;
const unsigned int CINCO_DE_MAYO = 10;
const unsigned int EASTER = 11;  //some crazy computation
const unsigned int GOOD_FRIDAY = 12;

const unsigned int SUNDAY = 0;
const unsigned int MONDAY = 1;
const unsigned int TUESDAY = 2;
const unsigned int WEDNESDAY = 3;
const unsigned int THURSDAY = 4;
const unsigned int FRIDAY = 5;
const unsigned int SATURDAY = 6;
 
 

class Holiday {
  
   private:
    boolean enabled;
    int timeGroup;  //yearly or daily    
    int MST;  //most significant time.. either be the month or the hour (depends on timegroup)
    int LST;  //least signifiact time... either the day of the month or the minute (depends on timegroup)
    int LST_index; //used to clarify more information about the LST
    
    uint32_t colorSwatches[3];
    int numColors;
   
    
   
   
    static const int SIZE = 10;      // initial size of the array
    int *Items;                      // Items will point to the dynamically allocated array
    int numItems;                    // number of items currently in the list
    int arraySize;                   // the current size of the array
    
    
  public:
    Holiday(int timeGroup, int mst, int lst);
    Holiday(int timeGroup, int mst, int lst, int lst_index);

   Holiday();
    boolean isActive();              // add k to the end of the list
    void addColor(uint32_t color);    
    uint32_t getPixelColors(int pixelIndex, int animFrame);
 
};
#endif
