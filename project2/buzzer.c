#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"
#include "switches.h"

#define MIN_PRD 1000 //Min and max periods for buzzers
#define MAX_PRD 4000

static unsigned int prd = 1000;
static signed int rate = 200;

//I will be using buzzer_init and buzzer_set_period from demos.

void buzzer_init()
{
  timerAUpmode(); //Used to drive speaker
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6; //Enable out to speaker (P2.6)
  //Used demo code
}
void buzzer_set_period(short cycles)
{
  CCR0 = cycles;
  CCR1 = cycles >> 1; //One half cycle Bitwise
  //Used Demo code
}
void buzzer_adv_freq()
{
  prd+=rate; //prd adds 200 until it reaches 4k

  if ((rate < 0 && (prd < MIN_PRD)) || (rate > 0 && (prd > MAX_PRD)))
    {
      rate = -rate; //If rate goes below 0 and we are below min prd OR if rate goes above 0 and we are above the max then rate flips
      prd += (rate << 1); //move bitwise 
    }

  buzzer_set_period(prd);
}
