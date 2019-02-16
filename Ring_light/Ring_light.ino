#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define NUMPIXELS       24      //number of pixels on ring
#define RING_PIN        14      //pin for ring
#define BUTTON_PIN      4       //pin for button
#define delay           200     //delay between pixels lighting up

int skipArray[] = {1, 5, 7, 11, 13, 17, 19, 23};
int buttonState = HIGH;
unsigned long t = 0;            //time variable
unsigned long tStamp = 0;       //future time at which an event happens (t + delay)
unsigned long count = 0;

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, RING_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {

  buttonState = digitalRead(BUTTON_PIN);
  t = millis();
  int j = (count*skipArray[0])%24;
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  
  
  if (buttonState == HIGH){
    if(tStamp <= t){
      tStamp = t + delay;

      if(j==0){
        count = 0;
      }

      if(pixels.getPixelColor(j) == 0){
        pixels.setPixelColor(j, pixels.Color(50,0,40)); // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      } else {
        pixels.setPixelColor(j, pixels.Color(0,0,0));
      }
      pixels.show(); // This sends the updated pixel color to the hardware.
      count++;
    }
  } else {
    t = 0;
    count = 0;
    for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(0,0,50));
      pixels.show();
    }
  }
}
