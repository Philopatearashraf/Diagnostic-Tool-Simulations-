/********************************/
/*Module Name : Switches.c      */
/*Authors : Nourhan Ayman       */
/*          Philopatear Ashraf  */
/*Purpose : Final Project       */
/********************************/
#include "Switches.h"
#include "Delay.h"
#include "CAN0.h"
/*CAN counters */
extern volatile uint32_t g_ui32MsgCount_Transmit;
extern volatile uint32_t g_ui32MsgCount_Receive;
/*CAN objects*/
extern tCANMsgObject sCANMessage_StateMachine;
extern tCANMsgObject g_sCANMsgObject_Transmit;
extern tCANMsgObject g_sCANMsgObject_Receive;
extern uint8_t ui32MsgData;
extern uint8_t *pui8MsgData_Transmit;
/*Receiver Buffer*/
extern uint8_t MsgData[8];
/*Transmitting Buffers*/
extern uint8_t g_pui8Msg0;
extern uint8_t g_pui8Msg1;
extern uint8_t g_pui8Msg2;
extern uint8_t g_pui8Msg3;
extern uint8_t g_pui8Msg4;
extern uint8_t g_pui8Msg5;
/*Error Flags*/
extern volatile bool g_bRXFlag;
extern volatile bool g_bErrFlag;
extern uint32_t obj2 ;
uint32_t SW1_StateMachine = 0x31;
uint32_t SW2_StateMachine = 0x32;
uint32_t set = 1;

void Switches_Interrupt_Init (void)
{
    SysCtlPeripheralEnable((uint32_t)SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput((uint32_t)GPIO_PORTF_BASE, (uint8_t)GPIO_PIN_1|(uint8_t)GPIO_PIN_2|(uint8_t)GPIO_PIN_3); /*RED LED*/
    HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK) = (uint32_t*)GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE+GPIO_O_CR) |= (uint32_t)0x1F;
    GPIOPinTypeGPIOInput((uint32_t)GPIO_PORTF_BASE, (uint8_t)GPIO_PIN_4|(uint8_t)GPIO_PIN_0  );
    GPIOPadConfigSet((uint32_t)GPIO_PORTF_BASE,(uint8_t) GPIO_PIN_4|(uint8_t)GPIO_PIN_0 , (uint32_t)GPIO_STRENGTH_2MA,(uint32_t) GPIO_PIN_TYPE_STD_WPU);
    GPIOIntTypeSet((uint32_t)GPIO_PORTF_BASE, (uint8_t)GPIO_PIN_4, (uint32_t)GPIO_FALLING_EDGE);
    GPIOIntRegister((uint32_t)GPIO_PORTF_BASE, &Switches_HANDLER);
    GPIOIntEnable((uint32_t)GPIO_PORTF_BASE, (uint32_t)GPIO_PIN_4|(uint32_t)GPIO_PIN_0 ); /* Enable the interrupt for Port F*/
    IntRegister((uint32_t)INT_GPIOF, &Switches_HANDLER); /* Register the interrupt handler function for Port F*/
    IntEnable((uint32_t)INT_GPIOF); /* Enable the interrupt for Port F*/
}

void Switches_HANDLER (void)
{
   uint32_t sw1 = (uint32_t)GPIO_PORTF_MIS_R & (uint32_t)GPIO_INT_PIN_0;
   uint32_t sw2 = GPIO_PORTF_MIS_R & (uint32_t)GPIO_INT_PIN_4;
    if (sw1 == set) /*if interrupt occurs on sw1*/
    {
        UARTprintf("SW1 (ClockWise) is Pressed.\n");
        Send_Command(obj2 , SW1_StateMachine, &g_pui8Msg1);
        DebouncingDelay ();
        if(g_bErrFlag)
         {
             UARTprintf(" error - cable connected?\n");
         }
    }
    else
    {
         UARTprintf("SW2 (Counter ClockWise) is Pressed.\n");
         Send_Command(obj2,SW2_StateMachine, &g_pui8Msg2);
         DebouncingDelay();
         if(g_bErrFlag)
          {
              UARTprintf(" error - cable connected?\n");
          }
    }
    GPIOIntClear((uint32_t)GPIO_PORTF_BASE, (uint32_t)GPIO_INT_PIN_0|(uint32_t)GPIO_INT_PIN_4);
}
