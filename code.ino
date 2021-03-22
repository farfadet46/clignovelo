#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define LED_PIN_G    8
#define LED_COUNT 10

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN_G, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {
//allée :
  colorWipeG(strip.Color(255, 20, 0), 50); // Red
  strip.clear();
  delay(500);
 /*   
 //retour :
  colorWipeD(strip.Color(255, 20, 0), 50); // Red
  strip.clear();
  delay(500);
  */
}

void colorWipeD(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}
void colorWipeG(uint32_t color, int wait) {
    for (int i = strip.numPixels(); i>-1; i--) { //pas sur de ce code :)
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}
