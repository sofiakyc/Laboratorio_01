#include <stdint.h>
#include <stdbool.h>
// includes da biblioteca driverlib
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"

void initPin4();

void main(void){
  initPin4();
  uint8_t LED_D4 = 0;
  int k = 0;
  
  while(1){  
    for (int j = 0; j < 3500000; j++){
        k = 0;
    }
    
    LED_D4 ^= GPIO_PIN_0; // Troca estado do LED D4
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, LED_D4); // Acende ou apaga LED D4
  } 
} 

void initPin4()
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // Habilita GPIO F (LED D3 = PF4, LED D4 = PF0)
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)); // Aguarda final da habilitação
      
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4); // LEDs D3 e D4 como saída
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4, 0); // LEDs D3 e D4 apagados
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4, GPIO_STRENGTH_12MA, GPIO_PIN_TYPE_STD);

}