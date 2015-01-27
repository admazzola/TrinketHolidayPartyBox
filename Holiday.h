#ifndef Holiday_h
#define Holiday_h

#include "Arduino.h"

 const int animationPeriod = 10; //seconds... animation only has a small chance of changing to the next random one after this!

 const int MAX_ANIM_COUNT = 12;
 
const uint32_t BLANK_COLOR = 0;
 
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

const unsigned int ANIM_NONE = 0; 
const unsigned int ANIM_ANTS = 1; //marching LEDs in circles
const unsigned int ANIM_SOLIDFADECYCLE = 2; //smooth fade thru colors,, all pixels are always the same color
const unsigned int ANIM_SNAKE = 4; //A linear fading of the colors snakes around in a circle
const unsigned int ANIM_GLIMMER = 8; //Mostly off, but shooting stars of the colors appear every 5 seconds
const unsigned int ANIM_TRIFORCE = 16; //Each color is at one-third intervals and snakes with a fading trail..goes faster and slower randomly
const unsigned int ANIM_CLOCK= 32;  //The 3 colors are the hour, minute, and second hands
const unsigned int ANIM_THIRDS= 64;  //Each color gets a continuous group of 4 LEDs, whole thing rotates
const unsigned int ANIM_SNAKEGAME= 128;  //One color is the snake, starts as a single LED. eats 'apples' which are LEDs of the other colors.  Snake gets longer when this is done.

class Holiday {
  
   private:
    boolean enabled;
    int timeGroup;  //yearly or daily    
    int MST;  //most significant time.. either be the month or the hour (depends on timegroup)
    int LST;  //least signifiact time... either the day of the month or the minute (depends on timegroup)
    int LST_index; //used to clarify more information about the LST
    
    uint32_t colorSwatches[3];
    int numColors;
    
    int currentAnimation;
   
    byte animationsMask;  //a bitmask for the types of animations to cycle through
   
    
    
  public:
    Holiday(int timeGroup, int mst, int lst);
    Holiday(int timeGroup, int mst, int lst, int lst_index);
    Holiday();
   
   
    boolean isActive();           
    void addColor(uint32_t color);    
    uint32_t getPixelColors(int pixelIndex, int animFrame);
    void setAnimations(byte bitmask);
};
#endif
