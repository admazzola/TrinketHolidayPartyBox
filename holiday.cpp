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



Holiday::Holiday(int timeGroup, int mst, int lst, int lst_index)
{
    enabled = true;
    this->timeGroup = timeGroup;
    this->MST = mst;
    this->LST = lst;
    this->LST_index = lst_index;
}

void Holiday::addColor(uint32_t color)
{
  this->colorSwatches[numColors] = color;
  
  numColors++;
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
