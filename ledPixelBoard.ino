#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// 15 x 10 Images (Frames)
#include "red_purple_grid_data.h"
#include "cat.h"
#include "thirteen.h"
#include "squad_u.h"
#include "u.h"
#include "TS_redFont.h"
#include "TS_blueFont.h"

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      150
#define NUMROWS        10
#define NUMCOLS        15
#define NUMCOLORS      3

// Construct NeoPixel Object
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Frame Transitions
int frame = 0;      // current frame
int numFrames = 2; // Frames (red_purple_grid_data, cat, thirteen, squad_u, u)
#define TOTALNUMFRAMES 2
int frameOrder[TOTALNUMFRAMES] = {0, 1};
int delayVal = 500; // 2 Hz
uint32_t newFrame[NUMPIXELS];

void setup() {
  // Initialize NeoPixel Library
  pixels.begin();
  //pixels.clear();
  pixels.setBrightness(32);   // 1/8 max brightness for now
}

void loop() {
    // Set up new frame
    setUpFrame(frame);

    // Write Pixels to Hardware
    pixels.show();

    // Wait and increment to next frame
    delay(delayVal);
    frame = (frame + 1) % TOTALNUMFRAMES;
}

void setUpFrame(int f) {
  // 1) Grab the frame number for this time
  int frameNumber = frameOrder[f];

  // 2) Grab the corresponding frame data pointer 
  switch(frameNumber) {
    case 0 :
      memcpy_P(newFrame, ts_red_font, 600);
      break;
    case 1 :
      memcpy_P(newFrame, ts_blue_font, 600);
      break;
    case 2 :
      //memcpy_P(newFrame, thirteen, 600);
      break;
    case 3 :
      //memcpy_P(newFrame, squad_u, 600);
      break;
    case 4 :
      //memcpy_P(newFrame, u, 600);
      break;
    default :
      return;
  }

  // 3) Copy the frame data to the library
  copyFrame2Pixels(newFrame);
}


/*   
    The LED pattern is shown below
     
          <<<<<<<<<<<<<<<
          >>>>>>>>>>>>>>>
          <<<<<<<<<<<<<<<
          >>>>>>>>>>>>>>>
          <<<<<<<<<<<<<<<
          >>>>>>>>>>>>>>>
          <<<<<<<<<<<<<<<
          >>>>>>>>>>>>>>>
          <<<<<<<<<<<<<<<
          >>>>>>>>>>>>>>>
   
 */ 
void copyFrame2Pixels(uint32_t *f) {
  // 1) "Forward Direction" Pixels >>>
  for (int i = NUMROWS-1; i >= 0; i = i - 2) {
    for (int j = 0; j < NUMCOLS; j++) {
      pixels.setPixelColor(j + (NUMROWS-i-1)*NUMCOLS, f[ rc2ind(i,j) ]);  
    }
  }

  // 2) "Backward Direction" Pixels <<<
  for (int i = NUMROWS-2; i >= 0; i = i - 2) {
      for (int j = 0; j < NUMCOLS; j++) {
        pixels.setPixelColor((NUMCOLS-1-j) + (NUMROWS-i-1)*NUMCOLS, f[ rc2ind(i,j) ]);  
    }
  }
}

int rc2ind(int row, int col) {
  return (row * NUMCOLS) + col;
}




