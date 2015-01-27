/* 
 * The trinket has maximum sketch size of 28,672 bytes
 * On Linux, you can use "date +T%s\n > /dev/ttyACM0" (UTC time zone)
 */  
 

#include <Time.h>  
#include <Adafruit_NeoPixel.h>
#include "Holiday.h"  

const unsigned long DEFAULT_TIME = 1422315564; //time when doing the download..unix time since epoch


//these are the types of 'holidays'.  Daily or Yearly.
const unsigned int YEARLY = 0;  //ints are for month and day of the month
const unsigned int DAILY = 1;  //ints are for hour and min

const unsigned int ELEVEN_ELEVEN = 0;





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
  uint32_t COLOR_PURPLE = pixels.Color(20, 20, 200);
  uint32_t COLOR_GREEN = pixels.Color(20, 20, 200);
  uint32_t COLOR_BLACK = pixels.Color(20, 20, 200);
  
  holidays[ELEVEN_ELEVEN] = Holiday(DAILY,23,11,COLOR_PURPLE, COLOR_WHITE);
  //holidays[JULY_FOUR] = new Holiday(DAILY,23,11,COLOR_RED,COLOR_WHITE,COLOR_BLUE);
  
  
}  

  

