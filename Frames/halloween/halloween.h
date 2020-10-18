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

// Spider (Mode 2)
#include "spider/spider_1.h"
#include "spider/spider_2.h"
#include "spider/spider_3.h"
#include "spider/spider_4.h"
#include "spider/spider_5.h"
#include "spider/spider_6.h"
#include "spider/spider_7.h"
#include "spider/spider_8.h"
#include "spider/spider_9.h"
#include "spider/spider_10.h"
#include "spider/spider_11.h"
#include "spider/spider_12.h"

// Universal Frames
#include "../blank.h"

//////////////////////////////////////////////////////
//                                                  //
//           Define how frames are switched         //
//                                                  //
//////////////////////////////////////////////////////

#define CYCLE_THROUGH_MODES
#define NUM_MODES 3
#define NUM_FRAMES 20   // Number of frames in each mode (frames can repeat)
int delayVal = 200;     // Constant delay value between frames

// Order/Duration of frames in each mode
int mode_frames[NUM_MODES][NUM_FRAMES] = {
  {0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},  // Mode 0 (Pumpkin)
  {3, 4, 3, 4, 3, 4, 3, 4, 3, 4, 3, 4, 3, 4, 3, 4, 3, 4, 3, 4},  // Mode 1 (Zombie)
  {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16},  // Mode 2 (Spider)
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
    case 5 :
      memcpy_P(newFrame, spider_1, 600);      
      break;   
    case 6 :
      memcpy_P(newFrame, spider_2, 600);      
      break;   
    case 7 :
      memcpy_P(newFrame, spider_3, 600);      
      break;   
    case 8 :
      memcpy_P(newFrame, spider_4, 600);      
      break;   
    case 9 :
      memcpy_P(newFrame, spider_5, 600);      
      break;   
    case 10 :
      memcpy_P(newFrame, spider_6, 600);      
      break;   
    case 11 :
      memcpy_P(newFrame, spider_7, 600);      
      break;   
    case 12 :
      memcpy_P(newFrame, spider_8, 600);      
      break;   
    case 13 :
      memcpy_P(newFrame, spider_9, 600);      
      break;   
    case 14 :
      memcpy_P(newFrame, spider_10, 600);      
      break;   
    case 15 :
      memcpy_P(newFrame, spider_11, 600);      
      break;   
    case 16 :
      memcpy_P(newFrame, spider_12, 600);      
      break;   
    default :
      return;
  }
}
