#include <stdio.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "libTimer.h"


int main(){
  configure_clock();
  
  switch_init();
  led_init();
  buzzer_init();
  buzzer_set_period(1000);

  return 0;
}
