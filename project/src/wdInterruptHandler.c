#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  /* check for any updates here */
  static char blink_count = 0;
  static char time_frame;
  int bpm =  150;
  
  if(state == 1)
    time_frame = 125;

  else if(state == 4) /* last state */
    time_frame = (char)((15000 / (2 * bpm)));
  
  else
    time_frame = 1;

  if (++blink_count == time_frame) {
    state_advance();
    blink_count = 0;
  }
}
