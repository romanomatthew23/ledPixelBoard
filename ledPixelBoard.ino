#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

//////////////////////////////////////////////////////
//                                                  //
//                    Frames                        //
//                                                  //
//////////////////////////////////////////////////////

// Je Suis Calme! (Mode 0)
#include "Je.h"
#include "suis.h"
#include "calme.h"

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
#define NUM_MODES 5

// Frames
int frame = 0;          // current frame
#define NUM_FRAMES 20   // Number of frames in each mode (frames can repeat)
int delayVal = 200;     // Constant delay value between frames
uint32_t newFrame[NUMPIXELS];

// Order/Duration of frames in each mode
int mode_frames[NUM_MODES][NUM_FRAMES] = {
  { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, // Mode 0 (Je Suis Calme!) (0-2)
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
      memcpy_P(newFrame, je, 600);
      break;
    case 1 :
      memcpy_P(newFrame, suis, 600);
      break;
    case 2 :
      memcpy_P(newFrame, calme, 600);
      break;
    case 3 :
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


