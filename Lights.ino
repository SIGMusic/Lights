#include "LPD8806.h"
#include "SPI.h"

int nLEDs = 32;
int dataPin = 2;
int clockPin = 3;
uint8_t wait = 10; 

LPD8806 strip = LPD8806(nLEDs, dataPin, clockPin);

void setup()
{
  strip.begin(); 
  strip.show();
}

void loop()
{
  uint8_t wait = 10; 
  int i, j; 
  for (j=0; j < 384; j++)
    {
      for (i=0; i < strip.numPixels(); i++)
        {
          /* 
             TODO
             Implement controlling RGB lights
             x = constant * getHandValue();
             y = getStatus();
             strip.setPixelColor(i, getandValue  % 384));
          */
          strip.setPixelColor(i, Wheel( (i + j)  % 384));
        }     
       strip.show();
       delay(wait);
    }
}

/*
  Helper function for RGB strip library
*/

uint32_t Wheel(uint16_t WheelPos)
{
  byte r, g, b;
  switch(WheelPos / 128)
  {
    case 0:
      r = 127 - WheelPos % 128;   //Red down
      g = WheelPos % 128;      // Green up
      b = 0;                  //blue off
      break; 
    case 1:
      g = 127 - WheelPos % 128;  //green down
      b = WheelPos % 128;      //blue up
      r = 0;                  //red off
      break; 
    case 2:
      b = 127 - WheelPos % 128;  //blue down 
      r = WheelPos % 128;      //red up
      g = 0;                  //green off
      break; 
  }
  return(strip.Color(r,g,b));
}
