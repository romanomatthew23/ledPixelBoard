#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

//////////////////////////////////////////////////////
//                                                  //
//                    Frames                        //
//                                                  //
//////////////////////////////////////////////////////

// We Love TS (Mode 0)
#include "we.h"
#include "small_heart.h"
#include "bigger_heart.h"
#include "biggest_heart.h"
#include "TS_redFont.h"
#include "TS_blueFont.h"
#include "taytay.h"
#include "TS_blue_only.h"

// rep (Mode 1)
#include "rep.h"

// LWYMMD Cat Squad (Mode 2)
#include "cat_super_new.h"
#include "thirteen.h"
#include "squad_u.h"
#include "u.h"

// Are you ready for it? (Mode 3)
#include "Are_you_.h"
#include "ready_stacked.h"
#include "_for_it.h"
#include "Question_Mark.h"

// Delicate (Mode 4)
#include "cate_new.h"
#include "deli_new.h"
#include "del.h"
#include "i.h"
#include "cate_newest.h"

// Crown Heart (Mode 5)
#include "crown_heart_better.h"

// NYD (Mode 6)
#include "nyd.h"

// Snake (Mode 7)
#include "snake.h"

// Universal Frames
#include "blank.h"




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

// Modes 
int mode = 0;
#define NUM_MODES 8

// Frames
int frame = 0;          // current frame
#define NUM_FRAMES 20   // Number of frames in each mode (frames can repeat)
int delayVal = 200;     // Constant delay value between frames
uint32_t newFrame[NUMPIXELS];

// Order/Duration of frames in each mode
int mode_frames[NUM_MODES][NUM_FRAMES] = {
  {0,0,0,1,2,3,1,2,3,4,4,5,5,4,4,5,5,6,6,6}, // Mode 0 (0-6)
  {7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7}, // Mode 1 (7)
  {8,8,8,8,8,9,9,9,9,9,10,10,10,10,10,11,11,11,11,11}, // Mode 2 (8-11)
  {12,12,12,12,12,13,13,13,13,13,14,14,14,14,14,15,15,15,15,15}, // Mode 3 (12-15)
  {16,16,16,16,16,17,17,17,17,17,16,16,16,16,16,17,17,17,17,17}, // Mode 4 (16-17)
  {18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18}, // Mode 5 (18)
  {19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19}, // Mode 6 (19)
  {20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20}  // Mode 7 (20)
};



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
    setUpFrame();

    // Write Pixels to Hardware
    pixels.show();

    // Wait and increment to next frame
    delay(delayVal);
    frame = (frame + 1) % NUM_FRAMES;
}

void setUpFrame() {
  // 1) Grab the frame number for this time
  // int frameNumber = frameOrder[f];
  int frameNumber = mode_frames[mode][frame];

  // 2) Grab the corresponding frame data pointer 
  switch(frameNumber) {
    case 0 :
      memcpy_P(newFrame, we, 600);
      break;
    case 1 :
      memcpy_P(newFrame, small_heart, 600);
      break;
    case 2 :
      memcpy_P(newFrame, bigger_heart, 600);
      break;
    case 3 :
      memcpy_P(newFrame, biggest_heart, 600);
      break;
    case 4 :
      memcpy_P(newFrame, ts_red_font, 600);      
      break;
    case 5 :
      memcpy_P(newFrame, ts_blue_font, 600);      
      break;
    case 6 :
      memcpy_P(newFrame, taytay, 600);
      break;
    case 7 :
      memcpy_P(newFrame, rep, 600);
      break;
    case 8 :
      memcpy_P(newFrame, cat_super_new, 600);
      break;
    case 9 :
      memcpy_P(newFrame, thirteen, 600);
      break;
    case 10 :
      memcpy_P(newFrame, squad_u, 600);
      break;
    case 11 :
      memcpy_P(newFrame, u, 600);
      break;
    case 12 :
      memcpy_P(newFrame, are_you_, 600);
      break;
    case 13 :
      memcpy_P(newFrame, ready_stacked, 600);
      break;
    case 14 :
      memcpy_P(newFrame, _for_it, 600);
      break;
    case 15 :
      memcpy_P(newFrame, question_mark, 600);
      break;
    case 16 :
      memcpy_P(newFrame, deli_new, 600);
      break;
    case 17 :
      memcpy_P(newFrame, cate_new, 600);
      break;
    case 18 :
      memcpy_P(newFrame, crown_heart_better, 600);
      break;
    case 19 :
      memcpy_P(newFrame, nyd, 600);
      break;
    case 20 :
      memcpy_P(newFrame, snake, 600);
      break;
    case 21 :
      memcpy_P(newFrame, blank, 600);
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
    //frame = (frame + 1) % TOTALNUMFRAMES;
    mode = (mode + 1) % NUM_MODES;
    frame = 0;
    timeSinceLastInt = millis();  
  }
  
}


