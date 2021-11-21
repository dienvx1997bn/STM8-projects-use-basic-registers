#include <iostm8s003f3.h>

void delay_init() {
  //config timmer
  TIM4_PSCR = 3;        //Prescaler value = 2^pscr
  TIM4_EGR_UG = 1;      //if use update event then enable
  TIM4_CR1_CEN = 1;     //Enable timer 4
}

void delay_ms(unsigned int value) {
  // default clock source is 2MHz, prescale = 8, so clock for timer 4 is 250kHz
  for(unsigned int i = 0; i < value; i++) {
    TIM4_CNTR = 0;      
    while(TIM4_CNTR < 250);
  }
}

void delay_ms2(unsigned int value) {
  for(unsigned int i = 0; i < value; i++) {
    TIM4_CNTR = 6;              //set counter value = 6, increase from 6 to 255
    TIM4_SR_UIF = 0;            //clear flag interrupt
    while(TIM4_SR_UIF == 0);    //wait for interrupt
  }
}

int main( void )
{
  //config led
  PB_DDR = 1 << 5;      //B5 as output
  PB_CR1 = 1 << 5;      //out put push pull
  PB_CR2 = 0 << 5;      //low speed 2M
  PB_ODR_ODR5 = 1;      //clear output
  
  delay_init();
  
  while(1) {
    PB_ODR_ODR5 = !PB_ODR_ODR5;
    delay_ms2(100);
  }
}
