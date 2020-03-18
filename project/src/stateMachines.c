#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

static char state = 0;

void state_advance() {
  /* alternate between toggling red & green */
  switch(state) {
    case 0:
      blinking_state = 1; /* 1 == blinking lights */
      toggle_leds();
      break;
    case 1:
      blinking_state = 0; /* 0 == dimming lights */
      toggle_leds();
      break;
    case 2:
      toggle_leds();
      break;
    case 3:
      toggle_leds();
      break;
  }
    
  led_changed = 1;
  led_update();
}



