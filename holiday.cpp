#include "Holiday.h"  

Holiday::Holiday()
{
    enabled = false;
    
    
}

Holiday::Holiday(int timeGroup, int mst, int lst, uint32_t colorOne)
{
    enabled = true;
    this->timeGroup = timeGroup;
    this->MST = mst;
    this->LST = lst;
    
    this->colorSwatches[0] = colorOne;
    numColors = 1;
}

Holiday::Holiday(int timeGroup, int mst, int lst, uint32_t colorOne , uint32_t colorTwo )
{
    enabled = true;
    this->timeGroup = timeGroup;
    this->MST = mst;
    this->LST = lst;
    
    this->colorSwatches[0] = colorOne;
    this->colorSwatches[1] = colorTwo;
    numColors = 2;
}


Holiday::Holiday(int timeGroup, int mst, int lst, uint32_t colorOne, uint32_t colorTwo, uint32_t colorThree)
{
    enabled = true;
    this->timeGroup = timeGroup;
    this->MST = mst;
    this->LST = lst;
    
    this->colorSwatches[0] = colorOne;
    this->colorSwatches[1] = colorTwo;
    this->colorSwatches[2] = colorThree;
    numColors = 3;
}




boolean Holiday::isActive()
{
   if(enabled){
       //test day and stuff
       
       return true;
   }
   
    
   return false; 
}

void copy(int *a, int *b, int b_size) {
     if(b_size == 0) return;    
     *a = *b;
     copy(++a, ++b, b_size-1);
}

void Holiday::getPixelColors(int pixelIndex, int rgb[3]) //needs to depend on animation type and color swatch
{
  rgb[0] = 0;
  rgb[1] = 150;
  rgb[2] = 0;


}
