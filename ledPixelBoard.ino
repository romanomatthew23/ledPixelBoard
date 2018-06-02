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
//#include "crown.h"
//#include "crown_heart.h"
#include "rep.h"

#include "Are_you_.h"
#include "Question_Mark.h"
#include "_cate.h"
#include "_for_it.h"
#include "crown_heart_better.h"
#include "deli.h"
//#include "normal_crown.h"
//#include "rEaDy.h"

#include "bigger_heart.h"
#include "biggest_heart.h"
#include "cate_new.h"
#include "deli_new.h"
//#include "getaway_car.h"
#include "nyd.h"
#include "ready_stacked.h"
#include "small_heart.h"
#include "we.h"

#include "snake.h"
#include "taytay.h"

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            6
#define INTERRUPT_PIN  3
#define INT_COOLDOWN   500
unsigned long timeSinceLastInt;

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      150
#define NUMROWS        10
#define NUMCOLS        15
#define NUMCOLORS      3

// Construct NeoPixel Object
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GBR + NEO_KHZ800);

// Frame Transitions
int frame = 0;      // current frame
int numFrames = 17; // Frames (red_purple_grid_data, cat, thirteen, squad_u, u)
#define TOTALNUMFRAMES 17
int frameOrder[TOTALNUMFRAMES] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
int delayVal = 200; // 2 Hz
uint32_t newFrame[NUMPIXELS];

void setup() {
  // Setup interrupt Pin
  pinMode(INTERRUPT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), buttonInput, FALLING);
  timeSinceLastInt = millis();
  
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
    //frame = (frame + 1) % TOTALNUMFRAMES;
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
      memcpy_P(newFrame, crown_heart_better, 600);
      break;
    case 3 :
      memcpy_P(newFrame, rep, 600);
      break;
    case 4 :
      memcpy_P(newFrame, are_you_, 600);
      break;
    case 5 :
      memcpy_P(newFrame, ready_stacked, 600);
      break;
    case 6 :
      memcpy_P(newFrame, _for_it, 600);
      break;
    case 7 :
      memcpy_P(newFrame, question_mark, 600);
      break;
    case 8 :
      memcpy_P(newFrame, deli_new, 600);
      break;
    case 9 :
      memcpy_P(newFrame, cate_new, 600);
      break;
    case 10 :
      memcpy_P(newFrame, small_heart, 600);
      break;
    case 11 :
      memcpy_P(newFrame, bigger_heart, 600);
      break;
    case 12 :
      memcpy_P(newFrame, biggest_heart, 600);
      break;
    case 13 :
      memcpy_P(newFrame, we, 600);
      break;
    case 14 :
      memcpy_P(newFrame, nyd, 600);
      break;
    case 15 :
      memcpy_P(newFrame, snake, 600);
      break;
    case 16 :
      memcpy_P(newFrame, taytay, 600);
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

void buttonInput() {
  if(millis() - timeSinceLastInt > INT_COOLDOWN) {
    frame = (frame + 1) % TOTALNUMFRAMES;
    timeSinceLastInt = millis();  
  }
  
}


