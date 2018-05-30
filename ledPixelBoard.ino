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


// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      150
#define NUMROWS        10
#define NUMCOLS        15
#define NUMCOLORS      3

// Construct NeoPixel Object
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Colors (0 x 00 R G B)
uint32_t i   = (0 << 24) | (255 << 16) | (192 << 8) | (203);    // pink
uint32_t p   = (0 << 24) | (255 << 16) |   (0 << 8) | (255);      // purple
uint32_t r   = (0 << 24) | (255 << 16) |   (0 << 8) | (0);     // red
uint32_t b   = (0 << 24) |   (0 << 16) |   (0 << 8) | (255);    // blue
uint32_t k   = (0 << 24) |   (0 << 16) |   (0 << 8) | (0);    // black

// Frames                  0  1  2  3  4  5  6  7  8  9  A  B  C  D  E
/*uint32_t cat[NUMPIXELS] = {i, i, i, i, i, i, i, i, i, i, i, i, i, i, i,   // 0
                           p, p, p, p, p, p, p, p, p, p, p, p, p, p, p,   // 1
                           p, p, p, p, p, p, p, p, p, p, p, p, p, p, p,   // 2
                           p, p, p, p, p, p, p, p, p, p, p, p, p, p, p,   // 3
                           p, p, p, p, p, p, p, p, p, p, p, p, p, p, p,   // 4
                           p, p, p, p, p, p, p, p, p, p, p, p, p, p, p,   // 5
                           p, p, p, p, p, p, p, p, p, p, p, p, p, p, p,   // 6
                           p, p, p, p, p, p, p, p, p, p, p, p, p, p, p,   // 7
                           p, p, p, p, p, p, p, p, p, p, p, p, p, p, p,   // 8
                           p, p, p, p, p, p, p, p, p, p, p, p, p, p, p};   // 9      */                        

// Frame Transitions
int frame = 0;      // current frame
int numFrames = 5; // Frames (red_purple_grid_data, cat, thirteen, squad_u, u)
#define TOTALNUMFRAMES 10
int frameOrder[TOTALNUMFRAMES] = {0, 1, 0, 1, 2, 4, 3, 4, 2, 4};
int delayVal = 500; // 2 Hz

void setup() {
  // Initialize NeoPixel Library
  pixels.begin();
  pixels.clear();
  pixels.setBrightness(25);   // 1/10 max brightness for now
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
  uint32_t *newFrame;

  // 2) Grab the corresponding frame data pointer 
  switch(frameNumber) {
    case '0' :
      memcpy(newFrame, red_purple_grid_data, 600);
      break;
    case '1' :
      memcpy(newFrame, cat, 600);
      break;
    case '2' :
      memcpy(newFrame, thirteen, 600);
      break;
    case '3' :
      memcpy(newFrame, squad_u, 600);
      break;
    case '4' :
      memcpy(newFrame, u, 600);
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
  for (uint16_t i = NUMROWS-1; i >= 0; i = i - 2) {
    for (uint16_t j = 0; j < NUMCOLS; j++) {
      pixels.setPixelColor(j + (NUMROWS-i-1)*NUMCOLS, f[ rc2ind(i,j) ]);  
    }
  }

  // 2) "Backward Direction" Pixels <<<
  for (uint16_t i = NUMROWS-2; i >= 0; i = i - 2) {
    for (uint16_t j = 0; j < NUMCOLS; j++) {
      pixels.setPixelColor((NUMCOLS-1-j) + (NUMROWS-i-1)*NUMCOLS, f[ rc2ind(i,j) ]);  
    }
  }
}


uint8_t rc2ind(uint8_t row, uint8_t col) {
  uint8_t ind = (row * NUMCOLS) + col;
}





