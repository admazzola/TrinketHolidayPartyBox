#include "Holiday.h"   
#include <Time.h>  


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



 int getWeekdayIndex(){
 
 return day()-1 /7;
 }

boolean Holiday::isActive()
{
   if(enabled){
       //test day and stuff
       if(timeGroup == DAILY){
           if(hour()==MST && minute() == LST){
             return true;
           } 
       }
       if(timeGroup == YEARLY){
           if(month()==MST && day() == LST){
             return true;
           } 
       }
        if(timeGroup == YEARLY_DAYDEPENDANT){
           if(month()==MST && weekday() == LST && getWeekdayIndex() == (LST_index)  ){  
             return true;
           } 
       }
       
       
       return false;
   }
   
    
   return false; 
}

 


uint32_t Holiday::getPixelColors(int pixelIndex, int animFrame) //needs to depend on animation type and color swatch
{
  //need to add animations to this by not always using 0!
  
  return colorSwatches[0];


}
