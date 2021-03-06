// MAKERTJEJ.se
// Workshop 1.3: Digibling Game- Gemma's Hat
//
// Extra program #1:
// Lights up special alignment pixels, used to "calibrate" the 
// rings' positions in relation to each other.
//

#include <Adafruit_NeoPixel.h>

#define PIN0 0
#define PIN1 1
#define PIN2 2

uint32_t off = 0; //off
uint32_t blue = 1; //blue
uint32_t orange = 2; //orange
uint32_t green = 3; //green

//off, blue, orange, green
uint32_t myColors[4] = {0x000000, 0x000066, 0xff6600, 0x00ff00};

//ALIGNMENT VERSION
static char round1[16] = {blue, off, off, off, off, off, off, off, off, off, off, off, off, off, off, orange}; //first circle
static char round2[16] = {orange, off, off, off, off, off, off, off, off, off, off, off, off, off, off, green}; //upper part of second circle
static char round3[12] = {green, off, off, off, off, off, off, off, off, off, off, orange}; //third circle
static char round4[8] = {orange, off, off, off, off, off, off, blue}; //lower part of second circle

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(52, PIN0, NEO_GRB + NEO_KHZ800);


void setup() {
  
  strip.begin();
  strip.show(); // Initialize all pixels to default

  strip.setBrightness(10); // 1/10 brightness to save battery

  lightup();
  
}

void loop() {
  
}


void lightup() {
  
  for (uint8_t i=0; i<16; i++) {
    strip.setPixelColor(15-i, myColors[round1[i]]);
  }

  for(uint8_t i=0; i<16; i++) {
    strip.setPixelColor(i+20, myColors[round2[i]]);
  }

  for(uint8_t i=0; i<12; i++) {
    strip.setPixelColor(i+40, myColors[round3[i]]);
  }

  for(uint8_t i=0; i<4; i++) {
    strip.setPixelColor(i+36, myColors[round4[i]]);
  }

  for(uint8_t i=0; i<4; i++) {
    strip.setPixelColor(i+16, myColors[round4[i+4]]);
  }

  strip.show();
}
