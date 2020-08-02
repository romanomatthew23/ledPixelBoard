#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

//////////////////////////////////////////////////////
//                                                  //
//                    Frames                        //
//                                                  //
//////////////////////////////////////////////////////

#include "Frames/reputation/reputation.h"

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



#define NUM_MODES 5
#define NUM_FRAMES 20   // Number of frames in each mode (frames can repeat)
int delayVal = 200;     // Constant delay value between frames

// Order/Duration of frames in each mode
int mode_frames[NUM_MODES][NUM_FRAMES] = {
  { 0, 0, 0,23, 1, 2, 3,23, 1, 2, 3, 4, 5, 4, 4, 6, 6, 6, 6, 6}, // Mode 0 (we <3 TAY TAY) (0-6),23 
  {38,38,38,38,24,24,24,25,26,27,28,29,30,30,42,42,43,43,44,44}, // Mode 1 (U-Squad)(8-11)  (24-30), 38, 42,43,44  
  {12,12,12,12,12,13,13,13,13,13,14,14,14,14,14,15,15,15,15,15}, // Mode 2 (are you ready for it?) (12-15) 
  {18,18,18,18,18,58,58,18,18,18,18,58,58,18,18,18,18,18,18,18}, // Mode 3 (crown heart) (18), 58
  { 7, 7, 21,7, 7, 7, 7,45,46,47,48,49,50,51,52,53,54,55,56,57}, // Mode 4 (rep & snake) (20) (31-35), 39, 40, 41 (45-56)
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
      //memcpy_P(newFrame, we, 600);
      memcpy_P(newFrame, we_blue_only, 600);
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
      //memcpy_P(newFrame, ts_red_font, 600);
      //memcpy_P(newFrame, ts_red_only, 600);
      memcpy_P(newFrame, ts_centered_red, 600);      
      break;
    case 5 :
      //memcpy_P(newFrame, ts_blue_font, 600);
      //memcpy_P(newFrame, ts_blue_only, 600);     
      memcpy_P(newFrame, ts_centered_blue, 600);   
      break;
    case 6 :
      memcpy_P(newFrame, taytay, 600);
      break;
    case 7 :
      memcpy_P(newFrame, rep, 600);
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
    case 18 :
      memcpy_P(newFrame, crown_heart_better, 600);
      break;
    case 21 :
      memcpy_P(newFrame, blank, 600);
      break;
    case 23 :
      memcpy_P(newFrame, teeniest_heart, 600);
      break;
    case 24 :
      memcpy_P(newFrame, big_u, 600);
      break;
    case 25 :
      memcpy_P(newFrame, squad_1, 600);
      break;
    case 26 :
      memcpy_P(newFrame, squad_2, 600);
      break;
    case 27 :
      memcpy_P(newFrame, squad_3, 600);
      break;
    case 28 :
      memcpy_P(newFrame, squad_4, 600);
      break;
    case 29 :
      memcpy_P(newFrame, squad_5, 600);
      break;
    case 30 :
      memcpy_P(newFrame, squad_6, 600);
      break;
    case 38 :
      memcpy_P(newFrame, cat_super_new, 600);
      break;
    case 42 :
      memcpy_P(newFrame, thirteen_big_red_1, 600);
      break;
    case 43 :
      memcpy_P(newFrame, thirteen_big_red_2, 600);
      break;
    case 44 :
      memcpy_P(newFrame, thirteen_big_red_3, 600);
      break;
      
    case 45 :
      memcpy_P(newFrame, snake_newest_1, 600);
      break;
    case 46 :
      memcpy_P(newFrame, snake_newest_2, 600);
      break;
    case 47 :
      memcpy_P(newFrame, snake_newest_3, 600);
      break;
    case 48 :
      memcpy_P(newFrame, snake_newest_4, 600);
      break;
    case 49 :
      memcpy_P(newFrame, snake_newest_5, 600);
      break;
    case 50 :
      memcpy_P(newFrame, snake_newest_6, 600);
      break;
    case 51 :
      memcpy_P(newFrame, snake_newest_7, 600);
      break;
    case 52 :
      memcpy_P(newFrame, snake_newest_8, 600);
      break;
    case 53 :
      memcpy_P(newFrame, snake_newest_9, 600);
      break;
    case 54 :
      memcpy_P(newFrame, snake_newest_10, 600);
      break;
    case 55 :
      memcpy_P(newFrame, snake_newest_11, 600);
      break;
    case 56 :
      memcpy_P(newFrame, snake_newest_12, 600);
      break;
    case 57 :
      memcpy_P(newFrame, snake_newest_13, 600);
      break;
    case 58 :
      memcpy_P(newFrame, crown_heart_bigger, 600);
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
