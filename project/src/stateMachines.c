#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char state; /* general state switched when pressing another button */
char blinking_state;

char switch_state_down1, switch_state_down2, switch_state_down3, switch_state_down4;

char check_state() {
  /* route each state to a button
     switch_state_down1 = state 0 
     ...
   */
  if(switch_state_down1 == 1)
    return 0;

  else if(switch_state_down2 == 1) 
    return 1;

  else if(switch_state_down3 == 1) 
    return 2;
  
  else if(switch_state_down4 == 1) 
    return 3;
  
}

void state_advance() {
  state = check_state();
  switch(state) {
    case 0: /* alternate between toggling red & green */
      blinking_state = 1; /* 1 == blinking lights */
      toggle_leds();
      break;
    case 1:
      blinking_state = 0; /* 0 == dimming lights */
      toggle_leds();
      break;
    case 2:
      blinking_state = 1;
      toggle_leds();
      break;
    case 3:
      blinking_state = 1;
      toggle_leds();
      break;
  }
    
  led_changed = 1;
  led_update();
}



