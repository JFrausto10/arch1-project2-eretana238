#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static char time_frame;
  
  if(state == 0 || state == 3)
    time_frame = 125;

  else
    time_frame = 1;

  if (++blink_count == time_frame) {
      state_advance();
      blink_count = 0;
    }
}
