#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  /* check for any updates here */
  static char blink_count = 0;
  char rate = 0;

  if (++blink_count == 125) {
    state_advance();
    blink_count = 0;
  }
}
