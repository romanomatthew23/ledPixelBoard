//////////////////////////////////////////////////////
//                                                  //
//           Include Individual Frames              //
//                                                  //
//////////////////////////////////////////////////////

// Pumpkin (Mode 0)
#include "pumpkin/pumpkin_1.h"
#include "pumpkin/pumpkin_2.h"
#include "pumpkin/pumpkin_3.h"

// Zombie (Mode 1)
#include "zombie/zombie_1.h"
#include "zombie/zombie_2.h"

// Universal Frames
#include "../blank.h"

//////////////////////////////////////////////////////
//                                                  //
//           Define how frames are switched         //
//                                                  //
//////////////////////////////////////////////////////

#define NUM_MODES 2
#define NUM_FRAMES 20   // Number of frames in each mode (frames can repeat)
int delayVal = 200;     // Constant delay value between frames

// Order/Duration of frames in each mode
int mode_frames[NUM_MODES][NUM_FRAMES] = {
  {0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},  // Mode 0 (Pumpkin)
  {3, 4, 3, 4, 3, 4, 3, 4, 3, 4, 3, 4, 3, 4, 3, 4, 3, 4, 3, 4},  // Mode 1 (Zombie)
};


void setUpFrame(uint32_t* newFrame) {
  // 1) Grab the frame number for this time
  // int frameNumber = frameOrder[f];
  int frameNumber = mode_frames[mode][frame];

  // 2) Grab the corresponding frame data pointer 
  switch(frameNumber) {
    case 0 :
      //memcpy_P(newFrame, we, 600);
      memcpy_P(newFrame, pumpkin_1, 600);
      break;
    case 1 :
      memcpy_P(newFrame, pumpkin_2, 600);
      break;
    case 2 :
      memcpy_P(newFrame, pumpkin_3, 600);
      break;
    case 3 :
      memcpy_P(newFrame, zombie_1, 600);
      break;
    case 4 :
      memcpy_P(newFrame, zombie_2, 600);      
      break;      
    default :
      return;
  }
}
