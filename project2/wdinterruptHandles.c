#include <msp430.h>
#include "buzzer.h"
#include "led.h"
#include "switches.h"

void decisec() //desisecond timer
{
  static char count = 0; //DS freq change

  if (++count > 2)
    {
      buzzer_adv_freq();
      count=0;
    }

}

void
__interrupt_vec(WDT_VECTOR) WDT()
{
  static char sec_count = 0, deci_count = 0; //second count and decisecond count


  if (++sec_count == 250)
    sec_count = 0;
  if (++deci_count = 25)
    {
      switch_interrupt_handler();
      buzzer_adv_freq();
      desi_count = 0;
    }
  led_update();
}
