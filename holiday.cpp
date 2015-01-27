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

void Holiday::setAnimations(byte bitmask)
{
  this->animationsMask = bitmask;  
}





 int getWeekdayIndex(){
 
 return (day()-1) /7;
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

 
int getRandomAnimation()
{
      int rand = random(300) % 8;

    return pow(2,rand);
}



uint32_t Holiday::getPixelColors(int pixelIndex, int animFrame) //needs to depend on animation type and color swatch
{
  //need to add animations to this by not always using 0!
  
  if(currentAnimation & animationsMask == 0 ) //if does no have the current animation
  {
      currentAnimation = getRandomAnimation();
      return BLANK_COLOR;
  }
  
  
    //if there is no anim set yet, roll for a new one
    if(currentAnimation == ANIM_NONE){
      
      currentAnimation = getRandomAnimation();
      
    }
   
   //if this anim cycle is over, roll for another (but only 15% chance)
    if(animFrame = MAX_ANIM_COUNT){
      int rand = random(100);
      if(rand < 15)
      {
        currentAnimation = getRandomAnimation();
      }
   }
  
  
  
  
  if(currentAnimation == ANIM_ANTS)
  {
    int cIndex = (animFrame + pixelIndex)%3;
    return colorSwatches[cIndex];
  }
  
  //need to check for the other animation styles like snake etc... will have to do some interesting functiosn to get fading to work
  
  
    
      
  
  return BLANK_COLOR;


}
