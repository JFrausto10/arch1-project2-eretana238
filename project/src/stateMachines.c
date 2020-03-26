#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "soundEngine.h"
#include "buzzer.h"

char state; /* general state switched when pressing another button */
char blinking_state; /* either blinking slow (1) or really fast (0) */

char switch_state_down1, switch_state_down2, switch_state_down3, switch_state_down4;

short song_state;




