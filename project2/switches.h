#ifndef switches_included
#define switches_included

//Basically using the demo code that was provided but I am using all four buttons.

#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3

#define SWITCHES (SW1|SW2|SW3|SW4)

//REST OF CODE DEMO
void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed; //Effectively boolean

#endif
