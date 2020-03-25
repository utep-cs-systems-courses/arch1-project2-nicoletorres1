#include <msp430.h>
#include "state_machine.h"
#include "led.h"

void led_state(int state)
{
  //Switch case to hopefully change into assembly code

  char flags = 0;

  switch(state)
    {
    case 0:
      flags |= LED_GREEN; //Button 1, green led
      P1OUT &= (0xff ^ LEDS) | flags;
      P1OUT |= flags;
      break;
    case 1:
      flags |= LED_RED; //Button 2 red led
      P1OUT &= (0xff ^ LEDS) | flags;
      P1OUT |= flags;
      break;
    case 2: //Button 3 Both LED
      flags |= LEDS;
      P1OUT &= (0xff ^ LEDS) | flags;
      P1OUT |= flags;
      break;
    case 3: //Button 4 No led
      P1OUT &= ~LEDS;
      break;
    default:
      break;
    }
  
}
