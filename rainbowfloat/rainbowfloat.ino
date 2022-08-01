// Adafruit_NeoMatrix example for single NeoPixel Shield.
// Displays pride flags and "Happy Pride" on two RGB matrices arranged vertically

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define PIN 6

// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_GRBW    Pixels are wired for GRBW bitstream (RGB+W NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(
  32, 8, 1, 2, 6, NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };

void setup() {
  matrix.begin();
  matrix.setTextWrap(true);
  matrix.setBrightness(5);
  matrix.setTextColor(colors[1]);
}

int x    = matrix.width();
int pass = 0;

void loop() {
  matrix.fillScreen(0);
  matrix.setCursor(0, 0);
  matrix.print(F("HappyPride "));
  matrix.show();
  delay(5000);

  //trans flag
  matrix.fillScreen(0);
  matrix.fillRect(0, 0, 32, 3, matrix.Color(122, 204, 246));
  matrix.fillRect(0, 3, 32, 6, matrix.Color(235, 174, 186));
  matrix.fillRect(0, 6, 32, 10, matrix.Color(200, 200, 200));
  matrix.fillRect(0, 10, 32, 13, matrix.Color(235, 174, 186));
  matrix.fillRect(0, 13, 32, 15, matrix.Color(122, 204, 246));
  matrix.show();
  delay(5000);

  //pride flag
  matrix.fillScreen(0);
  matrix.fillRect(0, 0, 32, 2, matrix.Color(227, 3, 3));
  matrix.fillRect(0, 2, 32, 5, matrix.Color(255, 139, 0));
  matrix.fillRect(0, 5, 32, 7, matrix.Color(254, 237, 0));
  matrix.fillRect(0, 7, 32, 10, matrix.Color(0, 128, 38));
  matrix.fillRect(0, 10, 32, 12, matrix.Color(0, 77, 255));
  matrix.fillRect(0, 12, 32, 15, matrix.Color(217, 6, 134));
  matrix.show();
  delay(5000);
}
