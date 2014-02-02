#include "LPD8806.h"
#include "SPI.h"

int nLEDs = 32;
int dataPin = 2;
int clockPin = 3;

LPD8806 strip = LPD8806(nLEDs, dataPin, clockPin);

void setup()
{
  strip.begin(); 
  strip.show();
}

void loop()
{
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
    }
    strip.show();
    delay(10);
}
