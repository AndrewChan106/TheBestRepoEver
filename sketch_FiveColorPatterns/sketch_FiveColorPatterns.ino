#include <Adafruit_CircuitPlayground.h>

int rightLEDS[5] = {0, 1, 2, 3, 4};
int leftLEDS[5] = {5, 6, 7, 8, 9};

const int buttonAPin = 4;
const int buttonBPin = 5;

volatile bool A_Flag = false;
volatile bool B_Flag = false;

volatile int modeControl = 0;

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(30);
}

void loop() {

  // sparkleWhite();
  // rainbowCycle(100,10);
  // redBlueSideSwitch();
  // blueRedWheel();
  blueLoadingWheel();
}


void sparkleWhite()
{
int randomLED = random(10);
for(int i = 0; i < 3; i++)
{
  CircuitPlayground.clearPixels();
  CircuitPlayground.setPixelColor(randomLED, 255, 255, 255);
  if(randomLED < 5)
  CircuitPlayground.setPixelColor(randomLED + 3, 255, 255, 255);
  if(randomLED > 5)
  CircuitPlayground.setPixelColor(randomLED - 4, 255, 255, 255);
  delay(30);
}
}





void rainbowCycle(int currentSpeed, int stripLen) {

  // Make an offset based on the current millisecond count scaled by the current speed.

  uint32_t offset = millis() / currentSpeed;

  // Loop through each pixel and set it to an incremental color wheel value.

  for(int i=0; i<10; ++i) {

    CircuitPlayground.setPixelColor(i, CircuitPlayground.colorWheel(((i * 256 / stripLen) + offset) & 255));

  }

}

void blueRedWheel()
{
for(int i = 0; i < 5; i++)
{
  CircuitPlayground.setPixelColor(rightLEDS[i], 0, 0, 255);
  CircuitPlayground.setPixelColor(leftLEDS[i], 255, 0, 0); 
}
  for(int i = 0; i < 10; i++)
  {
delay(500);
    if(i < 5)
    {
      CircuitPlayground.setPixelColor(rightLEDS[i], 255, 0, 0);
      CircuitPlayground.setPixelColor(leftLEDS[i], 0, 0, 255);
    }
    if(i >=5)
    {
      CircuitPlayground.setPixelColor(rightLEDS[i-5], 0, 0, 255);
      CircuitPlayground.setPixelColor(leftLEDS[i-5], 255, 0, 0);
    }
}
}


void redBlueSideSwitch()
{
CircuitPlayground.clearPixels();
  for(int p = 0; p < 10; p++)
  {
    if(p < 5)
    {
      for(int i = 0; i < 256; i++)
      {
        CircuitPlayground.setPixelColor(p, i, 0, 0);
        delay(1);
      }
    }
    if (p >= 5)
    {
      for(int i = 0; i < 256; i ++)
      {
        CircuitPlayground.setPixelColor(p, 0, 0, i);
        delay(1);
      }
    }
  }
        delay(500);
        CircuitPlayground.clearPixels();
        for(int i = 0; i < 5; i++)
        {
        CircuitPlayground.setPixelColor(rightLEDS[i], 0, 0, 255);
        CircuitPlayground.setPixelColor(leftLEDS[i], 255, 0, 0); 
        }
        delay(500);
        for(int i = 0; i < 5; i++)
        {
        CircuitPlayground.setPixelColor(rightLEDS[i], 255, 0, 0);
        CircuitPlayground.setPixelColor(leftLEDS[i], 0, 0, 255);
        }
        delay(1500);
}

void blueOnOffWheel()
{
CircuitPlayground.clearPixels();
  for(int p = 0; p<20; p++)
  {
    if(p<10)
    {
      for(int i = 0; i < 256; i++)
      {
        CircuitPlayground.setPixelColor(p, 0, 0, i);
        delay(1);
      }
      delay(200);
    }
    if(p>=10)
    {
      for(int i = 256; i < 512; i++)
      {
        CircuitPlayground.setPixelColor(p-10, 0, 0, 255-i);
        delay(1);
      }
    }
    delay(200);
  }
}
