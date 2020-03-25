#include <msp430.h>
#include "switches.h"
//Just used the interrupt handler that was provided in the demos
void
__interrupt_vec(PORT1_VECTOR) Port_1()
{
  if (P1IFG & SWITCHES)
    {
      P1IFG &= ~SWITCHES;
      switch_interrupt_handler();
    }
}
