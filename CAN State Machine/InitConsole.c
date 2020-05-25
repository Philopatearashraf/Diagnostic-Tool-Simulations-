/******************************************/
/*Module Name: InitConsole.c              */
/*Author: Nourhan Ayman                   */
/*        Philopatear Ashraf              */
/*Purpose: Final Project                  */
/******************************************/
#include "InitConsole.h"

void InitConsole(void)
{
    SysCtlClockSet((uint32_t)SYSCTL_SYSDIV_1 | (uint32_t)SYSCTL_USE_OSC | (uint32_t)SYSCTL_OSC_MAIN | (uint32_t)SYSCTL_XTAL_16MHZ);
    SysCtlPeripheralEnable((uint32_t)SYSCTL_PERIPH_GPIOA); /*Enable GPIO Peripheral PortA*/
    GPIOPinConfigure((uint32_t)GPIO_PA0_U0RX); /*Configuring PA0 for Receiving*/
    GPIOPinConfigure((uint32_t)GPIO_PA1_U0TX); /*Configuring PA1 for Transmitting*/
    SysCtlPeripheralEnable((uint32_t)SYSCTL_PERIPH_UART0); /*Enable UART Peripheral UART0 Module*/
    UARTClockSourceSet((uint32_t)UART0_BASE, (uint32_t)UART_CLOCK_PIOSC);
    GPIOPinTypeUART((uint32_t)GPIO_PORTA_BASE, (uint8_t)GPIO_PIN_0 | (uint8_t)GPIO_PIN_1);
    UARTStdioConfig((uint32_t)0, (uint32_t)115200, (uint32_t)16000000);
}


