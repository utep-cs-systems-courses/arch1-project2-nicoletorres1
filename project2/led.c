#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "libTimer.h"
#include "state_machine.h"

void led_test();

void led_init()
{
  P1DIR |= LEDS; //bits attaced to leds are output
  switch_state_changed = 1;
  led_test(0);//Test code using it for LED color

  led_update();
}
void led_update()
{
  //If the switch state changed this is where im making my toy do its thing, play a sound and put a led OR no sound, no LED
  if (switch_state_changed)
    {
      if (~P2IN & SW1) //Button One pressed, play 1080 freq and turn on GREEN LED
	{
	  buzzer_set_period(1080);
	  led_test(1);
	}
      else if (~P2IN & SW2) //Button Two pressed, play 1440 Freq and turn on Red LED
	{
	  buzzer_set_period(1440);
	  led_test(2);
	}
      else if (~P2IN & SW3) //Button Three pressed, play 2160 Freq and turn on Both LED
	{
	  buzzer_set_period(2160);
	  led_test(3);
	}
      else if (~P2IN & SW4) //Button Four pressed, turn off sound and LEDS
	{
	  buzzer_set_period(0);
	  led_test(0);
	}
    }
  switch_state_changed = 0;
}

