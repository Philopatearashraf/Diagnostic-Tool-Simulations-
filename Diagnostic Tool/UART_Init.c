/********************************/
/*Module Name : UART_Init.c     */
/*Authors : Nourhan Ayman       */
/*          Philopatear Ashraf  */
/*Purpose : Final Project       */
/********************************/
#include "UART_Init.h"
#include "CAN0.h"

extern uint8_t ui32MsgData;
extern uint8_t *pui8MsgData_Transmit;
/*Receiver Buffer*/
extern uint8_t MsgData[8];

void InitConsole(void)
{
    SysCtlClockSet((uint32_t)SYSCTL_SYSDIV_1 | (uint32_t)SYSCTL_USE_OSC | (uint32_t)SYSCTL_OSC_MAIN | (uint32_t)SYSCTL_XTAL_16MHZ);
    SysCtlPeripheralEnable((uint32_t)SYSCTL_PERIPH_GPIOA);
    GPIOPinConfigure((uint32_t)GPIO_PA0_U0RX);
    GPIOPinConfigure((uint32_t)GPIO_PA1_U0TX);
    SysCtlPeripheralEnable((uint32_t)SYSCTL_PERIPH_UART0);
    UARTClockSourceSet((uint32_t)UART0_BASE, (uint32_t)UART_CLOCK_PIOSC);
    GPIOPinTypeUART((uint32_t)GPIO_PORTA_BASE, (uint8_t)GPIO_PIN_0 | (uint8_t)GPIO_PIN_1);
    UARTStdioConfig((uint32_t)0, (uint32_t)115200,(uint32_t) 16000000);
}
void PrintCANMessageInfo(const tCANMsgObject *psCANMsg, uint32_t ui32MsgObj)
{
    UARTprintf("Sending msg: obj=%d ID=0x%X", ui32MsgObj, psCANMsg->ui32MsgID );
    UARTprintf("\n");
}
void PrintStatus(void)
{
    UARTprintf("Received MSG ID:0x%X  ",Get_MSG_ID());
    UARTprintf("Received MSG Data: %d\n",Get_MSG_Data());
}
