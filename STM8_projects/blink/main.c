#include <iostm8s003f3.h>

int main( void )
{
  unsigned int count = 50000;
  
  PB_DDR_DDR5 = 1;      //B5 as output
  PB_CR1 = 1 << 5;      //out put push pull
  PB_CR2 = 0 << 5;      //low speed 2M
  PB_ODR_ODR5 = 1;      //clear output
  
  while(1) {
    PB_ODR_ODR5 = !PB_ODR_ODR5;
    
    while(count-- > 0);
    count = 50000;
  }
}
