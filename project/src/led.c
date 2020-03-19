#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;
unsigned char led_state = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

void toggle_leds() {
  switch (led_state) {
    case 0: 
      red_on = 1;
      green_on = 0;
      break;
    case 1: 
      red_on = 0;
      green_on = 1;
      break;
    }

    led_state ^= 1;
}

void led_init() {
  P1DIR |= LEDS;		// bits attached to leds are output
  led_changed = 1;
  led_update();
}

void led_update() {
  char ledFlags = 0;
  if (blinking_state) {
    ledFlags = redVal[red_on] | greenVal[green_on];
  }
  else {
    ledFlags = greenVal[green_on];
  }
  
  P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
  P1OUT |= ledFlags;		     // set bit for on leds
  led_changed = 0;
}


