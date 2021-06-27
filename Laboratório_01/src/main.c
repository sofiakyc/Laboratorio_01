#include <stdint.h>
#include <stdbool.h>
// includes da biblioteca driverlib
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"

uint8_t LED_D4 = 0;

void main(void){
  int k = 0, n = 0;
  
  while (true){
    for (int j = 0; j < 3500000; j++){
        k = 0;
    }
    LED_D4 ^= GPIO_PIN_0; // Troca de estado
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, LED_D4); // Acende ou apaga do led
  }

}