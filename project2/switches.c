#include <msp430.h>
#include "switches.h"
#include "buzzer.h"
#include "led.h"

char switch_state_down, switch_state_changed; //Boolean
/* For this code I'm going to be using the demo code with some modifications because more buttons */

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN; //Using P2 instead of P1
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}

void
switch_init()
{
  //P2 again instead of P1
  P2REN |= SWITCHES;
  P2IE = SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
  switch_interrupt_handler();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  switch_state_down = (p2val & SW1) ? (p2val & SW2) ? (p2val & SW3) ? (p2val & SW4) ? 0 : 1 : 1 : 1 : 1; // 4 buttons
  switch_state_changed = 1;
  led_update();
}
