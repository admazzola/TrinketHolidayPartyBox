/* 
 * The trinket has maximum sketch size of 28,672 bytes
 * On Linux, you can use "date +T%s\n > /dev/ttyACM0" (UTC time zone)
 */  
 

#include <Time.h>  
#include <Adafruit_NeoPixel.h>
#include "Holiday.h"  

const unsigned long DEFAULT_TIME = 1422315564; //time when doing the download..unix time since epoch


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

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      12

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

Holiday holidays[30];

void setup()  {  
    
    
    
    
  setTime(DEFAULT_TIME); 
 
 
   setupHolidays();
 
   // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
    
}





void loop(){    

  updatePixelsColors();
  
  pixels.show();//push colors to hardware
  delay(50);
}

int holidayIndex;
int pixelIndex;
  int rgb[3];
void updatePixelsColors(){
  for(holidayIndex =0; holidayIndex < sizeof(holidays); holidayIndex++)
  {
    if(holidays[holidayIndex].isActive())
      {
          
        for(pixelIndex =0; pixelIndex < NUMPIXELS; pixelIndex++){
        
          holidays[holidayIndex].getPixelColors(pixelIndex,rgb);
          
          pixels.setPixelColor(pixelIndex, pixels.Color(rgb[0],rgb[1],rgb[2]));
          
        }
        
        break; //ignore the other holidays so 0 has highest priority
      }  
  }   
}




void digitalClockDisplay(){
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(month());
  Serial.print(" ");
  Serial.print(year()); 
  Serial.println(); 
}

void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}



//define animation patterns here


//define holiday color patterns here



//define which dates are which holidays


void setupHolidays(){
   uint32_t COLOR_RED = pixels.Color(200, 20, 20);
  uint32_t COLOR_WHITE = pixels.Color(200, 200, 200);
  uint32_t COLOR_BLUE = pixels.Color(20, 20, 200);
  uint32_t COLOR_PINK = pixels.Color(200, 100, 100);
  
  
  uint32_t COLOR_PURPLE = pixels.Color(20, 20, 200);
  uint32_t COLOR_GREEN = pixels.Color(20, 20, 200);
  uint32_t COLOR_BLACK = pixels.Color(20, 20, 200);
  uint32_t COLOR_YELLOW = pixels.Color(20, 20, 200);
  
  uint32_t COLOR_BROWN = pixels.Color(200, 100, 100);
  
  holidays[ELEVEN_ELEVEN_AM] = Holiday(DAILY,11,11); //11:11 am
  holidays[ELEVEN_ELEVEN_AM].addColor(COLOR_YELLOW);
  holidays[ELEVEN_ELEVEN_AM].addColor(COLOR_WHITE);
    
  holidays[ELEVEN_ELEVEN_PM] = Holiday(DAILY,23,11); //11:11 pm
  holidays[ELEVEN_ELEVEN_PM].addColor(COLOR_PURPLE);
  holidays[ELEVEN_ELEVEN_PM].addColor(COLOR_WHITE);
   
  holidays[ANNIVERSARY] = Holiday(YEARLY,11,11); //november 11th
  holidays[ANNIVERSARY].addColor(COLOR_GREEN);
  holidays[ANNIVERSARY].addColor(COLOR_WHITE);
  holidays[ANNIVERSARY].addColor(COLOR_PURPLE);
    
  holidays[BIRTHDAY] = Holiday(YEARLY,12,16);
  holidays[BIRTHDAY].addColor(COLOR_PURPLE);
  holidays[BIRTHDAY].addColor(COLOR_WHITE);
  holidays[BIRTHDAY].addColor(COLOR_BLUE);
      
  holidays[JULY_FOUR] = Holiday(YEARLY,7,4);
  holidays[JULY_FOUR].addColor(COLOR_RED);
  holidays[JULY_FOUR].addColor(COLOR_WHITE);
  holidays[JULY_FOUR].addColor(COLOR_BLUE);
  
  holidays[CHRISTMAS] = Holiday(YEARLY,12,25);
  holidays[CHRISTMAS].addColor(COLOR_RED);
  holidays[CHRISTMAS].addColor(COLOR_WHITE);
  holidays[CHRISTMAS].addColor(COLOR_GREEN);
    
  holidays[NEWYEARS] = Holiday(YEARLY,1,1); 
  holidays[NEWYEARS].addColor(COLOR_RED);
  holidays[NEWYEARS].addColor(COLOR_WHITE);
  holidays[NEWYEARS].addColor(COLOR_YELLOW);
    
  holidays[THANKSGIVING] = Holiday(YEARLY_DAYDEPENDANT,11,THURSDAY,4); //4th thursday of nov
  holidays[THANKSGIVING].addColor(COLOR_RED);
  holidays[THANKSGIVING].addColor(COLOR_WHITE);
  holidays[THANKSGIVING].addColor(COLOR_BROWN);
    
  holidays[HALLOWEEN] = Holiday(YEARLY,10,31); 
  holidays[HALLOWEEN].addColor(COLOR_RED);
  holidays[HALLOWEEN].addColor(COLOR_WHITE);
  holidays[HALLOWEEN].addColor(COLOR_YELLOW);
  
  holidays[LEIF_ERIKSON_DAY] = Holiday(YEARLY,10,9); 
  holidays[LEIF_ERIKSON_DAY].addColor(COLOR_BLUE);
  holidays[LEIF_ERIKSON_DAY].addColor(COLOR_PINK);
  holidays[LEIF_ERIKSON_DAY].addColor(COLOR_YELLOW);
  
  holidays[CINCO_DE_MAYO] = Holiday(YEARLY,5,5); 
  holidays[CINCO_DE_MAYO].addColor(COLOR_RED);
  holidays[CINCO_DE_MAYO].addColor(COLOR_WHITE);
  holidays[CINCO_DE_MAYO].addColor(COLOR_GREEN);
  
   /*
  holidays[EASTER] = Holiday(EASTER_OFFSET,0,0); 
  holidays[EASTER].addColor(COLOR_PINK);
  holidays[EASTER].addColor(COLOR_WHITE);
  holidays[EASTER].addColor(COLOR_PURPLE);
  
  holidays[GOOD_FRIDAY] = Holiday(EASTER_OFFSET,-3,0); 
  holidays[GOOD_FRIDAY].addColor(COLOR_PINK);
  holidays[GOOD_FRIDAY].addColor(COLOR_WHITE);
  holidays[GOOD_FRIDAY].addColor(COLOR_PURPLE);
  
 
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
  */
}  

  

