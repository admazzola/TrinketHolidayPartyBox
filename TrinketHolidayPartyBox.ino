/* 
 * The trinket has maximum sketch size of 28,672 bytes
 * Time is received by a DS1307RTC chip
 
On the trinket, pin 0 is SDA and pin 2 is SCL!  pin 1 will be for the LEDs data
 */  
 
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t
#include <Wire.h>  

#include <Time.h>  
#include <Adafruit_NeoPixel.h>
#include "Holiday.h"  

const unsigned long DEFAULT_TIME = 0; //time when doing the download..unix time since epoch


 int animationCounter = 0;
 
 
// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define NEOPIXELPIN            1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      12

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEOPIXELPIN, NEO_GRB + NEO_KHZ800);

Holiday holidays[30];

void setup()  {  
  

     
  setTime(DEFAULT_TIME); //not needed
  
   setSyncProvider(RTC.get);   // the function to get the time from the RTC
   setSyncInterval(10);//every 10 secs, sync with the RTC
 
   
   setupHolidays();
 
   // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
    
}



void loop(){   
   clearAllPixels(); //necessary?

  updatePixelsColors();
   
  
  pixels.show();//push colors to hardware
  
  delay(50);
  
  animationCounter++;
  if(animationCounter > MAX_ANIM_COUNT)
  {
    animationCounter = 0;
  }
}

int getAnimFrame()
{
  return animationCounter;
}


int holidayIndex;
int pixelIndex;
  int rgb[3];
  boolean noHolidays;
void updatePixelsColors(){
  
  //show debug pattern if the time is not set properly
  if(timeStatus() != timeSet)
  {
    debugBlink( pixels.Color(200,0,0));    
    return;
  }
  
  
  
  
  noHolidays = true;
  
  for(holidayIndex =0; holidayIndex < sizeof(holidays); holidayIndex++)
  {
    if(holidays[holidayIndex].isActive())
      {
          
        for(pixelIndex =0; pixelIndex < NUMPIXELS; pixelIndex++){
        
          uint32_t rgb = holidays[holidayIndex].getPixelColors(pixelIndex, getAnimFrame() );
          
          pixels.setPixelColor(pixelIndex,  rgb );
          
        }
        noHolidays = false;
        break; //ignore the other holidays so 0 has highest priority
      }  
  }   
  
  if(noHolidays)
  {
    updateDefaultClockAnimation();  
  }
  
  
}


void updateDefaultClockAnimation(){ //add really coo stuff here, just based on sec, min, and hour!
  
  
  
  for(pixelIndex =0; pixelIndex < NUMPIXELS; pixelIndex++){
    
    
    pixels.setPixelColor(pixelIndex, pixels.Color(1,200,3));
    
    
    
  }
  
  
  
  
}

//define animation patterns here



void setupHolidays(){
  uint32_t COLOR_RED = pixels.Color(200, 40, 20);
  uint32_t COLOR_WHITE = pixels.Color(200, 200, 200);
  uint32_t COLOR_BLUE = pixels.Color(80, 80, 240);
  uint32_t COLOR_PINK = pixels.Color(200, 150, 150); 
  uint32_t COLOR_PURPLE = pixels.Color(170, 50, 170);
  uint32_t COLOR_GREEN = pixels.Color(70, 200, 70);
  uint32_t COLOR_BLACK = pixels.Color(0, 0, 0);
  uint32_t COLOR_YELLOW = pixels.Color(200, 200, 20);
  uint32_t COLOR_ORANGE = pixels.Color(230, 150, 30);
  uint32_t COLOR_BROWN = pixels.Color(100, 70, 20);
  
  holidays[ELEVEN_ELEVEN_AM] = Holiday(DAILY,11,11); //11:11 am
  holidays[ELEVEN_ELEVEN_AM].addColor(COLOR_YELLOW);
  holidays[ELEVEN_ELEVEN_AM].addColor(COLOR_WHITE);
  holidays[ELEVEN_ELEVEN_AM].addColor(COLOR_BLACK);  
  holidays[ELEVEN_ELEVEN_AM].setAnimations( ANIM_ANTS | ANIM_SNAKE   );
    
  holidays[ELEVEN_ELEVEN_PM] = Holiday(DAILY,23,11); //11:11 pm
  holidays[ELEVEN_ELEVEN_PM].addColor(COLOR_PURPLE);
  holidays[ELEVEN_ELEVEN_PM].addColor(COLOR_WHITE);
  holidays[ELEVEN_ELEVEN_PM].addColor(COLOR_BLACK);  
  holidays[ELEVEN_ELEVEN_PM].setAnimations( ANIM_ANTS | ANIM_SNAKE   );
   
  holidays[ANNIVERSARY] = Holiday(YEARLY,11,11); //november 11th
  holidays[ANNIVERSARY].addColor(COLOR_GREEN);
  holidays[ANNIVERSARY].addColor(COLOR_WHITE);
  holidays[ANNIVERSARY].addColor(COLOR_PURPLE);
  holidays[ANNIVERSARY].setAnimations( ANIM_ANTS | ANIM_SNAKE   );
    
  holidays[BIRTHDAY] = Holiday(YEARLY,12,16);
  holidays[BIRTHDAY].addColor(COLOR_PURPLE);
  holidays[BIRTHDAY].addColor(COLOR_WHITE);
  holidays[BIRTHDAY].addColor(COLOR_BLUE);
  holidays[BIRTHDAY].setAnimations( ANIM_ANTS | ANIM_SNAKE   );
      
  holidays[JULY_FOUR] = Holiday(YEARLY,7,4);
  holidays[JULY_FOUR].addColor(COLOR_RED);
  holidays[JULY_FOUR].addColor(COLOR_WHITE);
  holidays[JULY_FOUR].addColor(COLOR_BLUE);
  holidays[JULY_FOUR].setAnimations( ANIM_ANTS | ANIM_SNAKE   );
  
  holidays[CHRISTMAS] = Holiday(YEARLY,12,25);
  holidays[CHRISTMAS].addColor(COLOR_RED);
  holidays[CHRISTMAS].addColor(COLOR_WHITE);
  holidays[CHRISTMAS].addColor(COLOR_GREEN);
  holidays[CHRISTMAS].setAnimations( ANIM_ANTS | ANIM_SNAKE   );
    
  holidays[NEWYEARS] = Holiday(YEARLY,1,1); 
  holidays[NEWYEARS].addColor(COLOR_RED);
  holidays[NEWYEARS].addColor(COLOR_WHITE);
  holidays[NEWYEARS].addColor(COLOR_YELLOW);
  holidays[NEWYEARS].setAnimations( ANIM_ANTS | ANIM_SNAKE   );
    
  holidays[THANKSGIVING] = Holiday(YEARLY_DAYDEPENDANT,11,THURSDAY,3); //thursday in the 4th week of nov  (int 3 is used since 0 is counted as the first week)
  holidays[THANKSGIVING].addColor(COLOR_RED);
  holidays[THANKSGIVING].addColor(COLOR_WHITE);
  holidays[THANKSGIVING].addColor(COLOR_BROWN);
  holidays[THANKSGIVING].setAnimations( ANIM_ANTS | ANIM_SNAKE   );
    
  holidays[HALLOWEEN] = Holiday(YEARLY,10,31); 
  holidays[HALLOWEEN].addColor(COLOR_RED);
  holidays[HALLOWEEN].addColor(COLOR_WHITE);
  holidays[HALLOWEEN].addColor(COLOR_YELLOW);
  holidays[HALLOWEEN].setAnimations( ANIM_ANTS | ANIM_SNAKE   );
  
  holidays[LEIF_ERIKSON_DAY] = Holiday(YEARLY,10,9); 
  holidays[LEIF_ERIKSON_DAY].addColor(COLOR_BLUE);
  holidays[LEIF_ERIKSON_DAY].addColor(COLOR_PINK);
  holidays[LEIF_ERIKSON_DAY].addColor(COLOR_YELLOW);
  holidays[LEIF_ERIKSON_DAY].setAnimations( ANIM_ANTS | ANIM_SNAKE   );
  
  holidays[CINCO_DE_MAYO] = Holiday(YEARLY,5,5); 
  holidays[CINCO_DE_MAYO].addColor(COLOR_RED);
  holidays[CINCO_DE_MAYO].addColor(COLOR_WHITE);
  holidays[CINCO_DE_MAYO].addColor(COLOR_GREEN);
  holidays[CINCO_DE_MAYO].setAnimations( ANIM_ANTS | ANIM_SNAKE   );
  
   /*
  holidays[EASTER] = Holiday(EASTER_OFFSET,0,0); 
  holidays[EASTER].addColor(COLOR_PINK);
  holidays[EASTER].addColor(COLOR_WHITE);
  holidays[EASTER].addColor(COLOR_PURPLE);
  
  holidays[GOOD_FRIDAY] = Holiday(EASTER_OFFSET,-3,0); 
  holidays[GOOD_FRIDAY].addColor(COLOR_PINK);
  holidays[GOOD_FRIDAY].addColor(COLOR_WHITE);
  holidays[GOOD_FRIDAY].addColor(COLOR_PURPLE);

  */
}  

void debugBlink(uint32_t debugColor)
{
   pixels.setPixelColor( getAnimFrame() , debugColor);
}

void clearAllPixels()
{

int i=0;
for(i=0;i<NUMPIXELS;i++){
   pixels.setPixelColor(i,  0);
}

}
