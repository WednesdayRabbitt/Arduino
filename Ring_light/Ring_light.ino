// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define NUMPIXELS       24      //number of pixels on ring
#define RING_PIN        14      //pin for ring
#define BUTTON_PIN      4       //pin for button
#define DELAY           50      //delay between pixels lighting up
#define SKIP            5       //number of pixels to skip when lighing up (1,5,7,11,13,17,19,23)

int buttonState = HIGH;
int t = 0;                      //time variable

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
  
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  
  for(int i=0;i<NUMPIXELS;i++){
    int j = (i)*SKIP%24;
    t = millis();
    
    if (buttonState == HIGH){
      pixels.setPixelColor(j, pixels.Color(0,0,50)); // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(DELAY); // Delay for a period of time (in milliseconds).
    } else {
      pixels.setPixelColor(i, pixels.Color(0,0,0));
      pixels.show();
    }
  }
}
