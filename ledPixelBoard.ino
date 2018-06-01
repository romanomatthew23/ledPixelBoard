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

// Debugging Flag (comment out to disable debugging)
// #define DEBUG         1


// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      150
#define NUMROWS        10
#define NUMCOLS        15
#define NUMCOLORS      3

// Construct NeoPixel Object
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Colors (0 x 00 R G B) ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
uint32_t i   = 0x00ff69b4;//((uint32_t)255 << 16) | ((uint32_t)192 <<  8) | 203;  // pink
uint32_t p   = 0x00ff00ff;   //(0 << 24) | (255 << 16) |   (0 << 8) | (255);      // purple

uint32_t r   = 0x00ff0000;  //(0 << 24) | (255 << 16) |   (0 << 8) | (0);     // red
uint32_t g   = 0x0000ff00;
uint32_t b   = 0x000000ff;    // blue

// Frames                  0  1  2  3  4  5  6  7  8  9  A  B  C  D  E
/*uint32_t cat_test[NUMPIXELS] = {r, r, r, r, r, r, g, g, g, g, g, g, g, b, b,   // 0
                           p, p, p, p, p, p, p, p, p, p, p, p, p, p, p,   // 1
                           p, p, p, p, p, p, p, p, p, p, p, p, p, p, p,   // 2
                           p, p, p, p, p, p, p, p, p, p, p, p, p, p, p,   // 3
                           p, p, p, p, p, p, p, p, p, p, p, p, p, p, p,   // 4
                           p, p, p, p, p, p, p, p, p, p, p, p, p, p, p,   // 5
                           p, p, p, p, p, p, p, r, g, b, p, p, p, p, p,   // 6
                           p, p, p, p, p, p, p, p, p, p, p, p, p, p, p,   // 7
                           p, p, p, p, p, p, p, p, p, p, p, p, p, p, p,   // 8
                           p, p, p, p, p, r, g, b, p, p, p, p, p, p, p};   // 9  */    

/*uint32_t cat_test[150] = {
0xff4a0052, 0xff4a0052, 0xff000000, 0xff000000, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff000000, 0xff000000, 0xff4a0052, 0xff4a0052, 
0xff4a0052, 0xff000000, 0xff777777, 0xff777777, 0xff000000, 0xff000000, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff000000, 0xff000000, 0xff777777, 0xff777777, 0xff000000, 0xff4a0052, 
0xff4a0052, 0xff000000, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff000000, 0xff000000, 0xff000000, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff000000, 0xff4a0052, 
0xff4a0052, 0xff000000, 0xff777777, 0xff000000, 0xffffb4ec, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xffffb4ec, 0xff000000, 0xff777777, 0xff000000, 0xff4a0052, 
0xff4a0052, 0xff000000, 0xff777777, 0xff000000, 0xff000000, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff000000, 0xff000000, 0xff777777, 0xff000000, 0xff4a0052, 
0xff000000, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff000000, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff000000, 
0xff000000, 0xffc500ff, 0xffc500ff, 0xff777777, 0xff000000, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff000000, 0xff777777, 0xffc500ff, 0xffc500ff, 0xff000000, 
0xff000000, 0xffc500ff, 0xffc500ff, 0xff777777, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff777777, 0xffc500ff, 0xffc500ff, 0xff000000, 
0xff4a0052, 0xff000000, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff777777, 0xff000000, 0xff4a0052, 
0xff4a0052, 0xff4a0052, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff4a0052, 0xff4a0052
};*/

uint32_t squad_u_test[150] = {
0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 
0xff4a0052, 0xff4a0052, 0xff4a0052, 0xffffb4ec, 0xffffb4ec, 0xffffb4ec, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xffffb4ec, 0xffffb4ec, 0xffffb4ec, 0xff4a0052, 0xff4a0052, 0xff4a0052, 
0xff4a0052, 0xff4a0052, 0xff4a0052, 0xffffb4ec, 0xffffb4ec, 0xffffb4ec, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xffffb4ec, 0xffffb4ec, 0xffffb4ec, 0xff4a0052, 0xff4a0052, 0xff4a0052, 
0xffc500ff, 0xffc500ff, 0xffc500ff, 0xff0000ff, 0xff0000ff, 0xff0000ff, 0xffc500ff, 0xff4a0052, 0xffc500ff, 0xff0000ff, 0xff0000ff, 0xff0000ff, 0xffc500ff, 0xffc500ff, 0xff4a0052, 
0xffc500ff, 0xff4a0052, 0xff4a0052, 0xff0000ff, 0xffffb4ec, 0xff0000ff, 0xffc500ff, 0xff4a0052, 0xffc500ff, 0xff0000ff, 0xffffb4ec, 0xff0000ff, 0xffc500ff, 0xff4a0052, 0xffc500ff, 
0xffc500ff, 0xffc500ff, 0xffc500ff, 0xff0000ff, 0xff0000ff, 0xff0000ff, 0xffc500ff, 0xff4a0052, 0xffc500ff, 0xff0000ff, 0xff0000ff, 0xff0000ff, 0xffc500ff, 0xff4a0052, 0xffc500ff, 
0xff4a0052, 0xff4a0052, 0xffc500ff, 0xffffb4ec, 0xffffb4ec, 0xff0000ff, 0xffc500ff, 0xffffb4ec, 0xffc500ff, 0xff0000ff, 0xffffb4ec, 0xff0000ff, 0xffc500ff, 0xff4a0052, 0xffc500ff, 
0xffc500ff, 0xffc500ff, 0xffc500ff, 0xff4a0052, 0xffffb4ec, 0xff0000ff, 0xffc500ff, 0xffc500ff, 0xffc500ff, 0xff0000ff, 0xffffb4ec, 0xff0000ff, 0xffc500ff, 0xffc500ff, 0xff4a0052, 
0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xffffb4ec, 0xffffb4ec, 0xffffb4ec, 0xffffb4ec, 0xffffb4ec, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 
0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052
};

uint32_t  thirteen_test[150] = {
0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 
0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 
0xff4a0052, 0xff4a0052, 0xffc500ff, 0xffc500ff, 0xffc500ff, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xffc500ff, 0xffc500ff, 0xffc500ff, 0xffc500ff, 0xff4a0052, 0xff4a0052, 
0xff4a0052, 0xffc500ff, 0xffc500ff, 0xffc500ff, 0xffc500ff, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xffc500ff, 0xff4a0052, 0xff4a0052, 
0xff4a0052, 0xff4a0052, 0xff4a0052, 0xffc500ff, 0xffc500ff, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xffc500ff, 0xff4a0052, 0xff4a0052, 
0xff4a0052, 0xff4a0052, 0xff4a0052, 0xffc500ff, 0xffc500ff, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xffc500ff, 0xffc500ff, 0xffc500ff, 0xffc500ff, 0xff4a0052, 0xff4a0052, 
0xff4a0052, 0xff4a0052, 0xff4a0052, 0xffc500ff, 0xffc500ff, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xffc500ff, 0xff4a0052, 0xff4a0052, 
0xff4a0052, 0xff4a0052, 0xff4a0052, 0xffc500ff, 0xffc500ff, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xffc500ff, 0xff4a0052, 0xff4a0052, 
0xff4a0052, 0xffc500ff, 0xffc500ff, 0xffc500ff, 0xffc500ff, 0xffc500ff, 0xffc500ff, 0xff4a0052, 0xff4a0052, 0xffc500ff, 0xffc500ff, 0xffc500ff, 0xffc500ff, 0xff4a0052, 0xff4a0052, 
0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052, 0xff4a0052
};

// Frame Transitions
int frame = 0;      // current frame
int numFrames = 5; // Frames (red_purple_grid_data, cat, thirteen, squad_u, u)
#define TOTALNUMFRAMES 10
int frameOrder[TOTALNUMFRAMES] = {0, 1, 0, 1, 2, 4, 3, 4, 2, 4};
int delayVal = 500; // 2 Hz

void setup() {
  #ifdef DEBUG
  Serial.begin(9600);
  Serial.println("Start of setup()");
  #endif

  
  // Initialize NeoPixel Library
  pixels.begin();
  //pixels.clear();
  pixels.setBrightness(32);   // 1/4 max brightness for now
}

void loop() {
    #ifdef DEBUG
    Serial.println("Start of loop()");
    Serial.print("frame = ");
    Serial.println(frame);
    #endif

    // Set up new frame
    setUpFrame(frame);
    //pixels.setPixelColor(frame, pixels.Color(50,0,0)); // Moderately bright green color.

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
    case 0 :
      //memcpy(newFrame, red_purple_grid_data, 600);
      //pixels.setPixelColor(0, pixels.Color(50,0,0)); // Moderately bright green color.
      break;
    case 1 :
      //memcpy(newFrame, cat, 600);
      //pixels.setPixelColor(1, pixels.Color(50,0,0)); // Moderately bright green color.
      break;
    case 2 :
      //memcpy(newFrame, thirteen, 600);
      //pixels.setPixelColor(2, pixels.Color(50,0,0)); // Moderately bright green color.
      break;
    case 3 :
      //memcpy(newFrame, squad_u, 600);
      //pixels.setPixelColor(3, pixels.Color(50,0,0)); // Moderately bright green color.
      break;
    case 4 :
      //memcpy(newFrame, u, 600);
      //pixels.setPixelColor(4, pixels.Color(50,0,0)); // Moderately bright green color.
      break;
    default :
      //pixels.setPixelColor(10, pixels.Color(50,0,0)); // Moderately bright green color.
      return;
  }

  // 3) Copy the frame data to the library
  //copyFrame2Pixels(cat_test);
  //copyFrame2Pixels(squad_u_test);
  copyFrame2Pixels(thirteen_test);
  //copyFrame2Pixels(newFrame);
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

  /* Simple Copy (Works, but not what we want)
  for (int i=0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i,f[i]);
  }
  */
 
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





