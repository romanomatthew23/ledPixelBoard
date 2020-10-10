#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

//////////////////////////////////////////////////////
//                                                  //
//                    Frames                        //
//                                                  //
//////////////////////////////////////////////////////

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

int mode = 0;           // current mode
int frame = 0;          // current frame
uint32_t newFrame[NUMPIXELS];


// Select which design you want to use
// #include "Frames/reputation/reputation.h"
#include "Frames/halloween/halloween.h"


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
    setUpFrame(newFrame);
      
    // Copy the frame data to the library
    copyFrame2Pixels(newFrame);

    // Write Pixels to Hardware
    pixels.show();

    // Wait and increment to next frame
    delay(delayVal);
    frame = (frame + 1) % NUM_FRAMES;
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
