#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char state; /* general state switched when pressing another button */
char blinking_state; /* either blinking slow (1) or really fast (0) */

char switch_state_down1, switch_state_down2, switch_state_down3, switch_state_down4;

void state_advance() {
  switch(state) {
    case 0: /* alternate between toggling red & green */
      blinking_state = 1; /* 1 == blinking lights */
      toggle_leds();
      break;
    case 1:
      blinking_state = 0; /* 0 == dimming lights */
      led_red_on();
      break;
    case 2:
      blinking_state = 0; /* 0 == dimming lights */
      led_green_on();
      break;
    case 3:
      blinking_state = 1;
      toggle_leds();
      break;
  }
  
  led_changed = 1;
  led_update();
}



