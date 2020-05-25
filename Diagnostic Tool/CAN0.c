/********************************/
/*Module Name : CAN0.c          */
/*Authors : Nourhan Ayman       */
/*          Philopatear Ashraf  */
/*Purpose : Final Project       */
/********************************/
#include "CAN0.h"
#include "UART_Init.h"
/*CAN objects*/
tCANMsgObject sCANMessage_StateMachine;
tCANMsgObject g_sCANMsgObject_Transmit;
tCANMsgObject g_sCANMsgObject_Receive;
uint8_t ui32MsgData;
uint8_t *pui8MsgData_Transmit;
/*Receiver Buffer*/
uint8_t MsgData[8];
/*Transmitting Buffers*/
uint8_t g_pui8Msg0 =  0 ;
uint8_t g_pui8Msg1 =  1 ;
uint8_t g_pui8Msg2 =  2 ;
uint8_t g_pui8Msg3 =  3 ;
uint8_t g_pui8Msg4 =  4 ;
uint8_t g_pui8Msg5 =  5 ;
/*Error Flags*/
volatile bool g_bRXFlag = 0;
volatile bool g_bErrFlag = 0;
volatile bool zero = 0 ;
volatile bool one = 1;
extern uint32_t obj2 ;
uint32_t obj1 = 1;

void Init_CAN(void)
{
  SysCtlPeripheralEnable((uint32_t)SYSCTL_PERIPH_GPIOB);
  GPIOPinConfigure((uint32_t)GPIO_PB4_CAN0RX);
  GPIOPinConfigure((uint32_t)GPIO_PB5_CAN0TX);
  GPIOPinTypeCAN((uint32_t)GPIO_PORTB_BASE, (uint8_t)GPIO_PIN_4 | (uint8_t)GPIO_PIN_5);
  SysCtlPeripheralEnable((uint32_t)SYSCTL_PERIPH_CAN0);
  CANInit((uint32_t)CAN0_BASE);
  CANBitRateSet((uint32_t)CAN0_BASE, (uint32_t)SysCtlClockGet(), (uint32_t)500000);
  CANIntEnable((uint32_t)CAN0_BASE, (uint32_t)CAN_INT_MASTER | (uint32_t)CAN_INT_ERROR |(uint32_t) CAN_INT_STATUS);
  IntEnable((uint32_t)INT_CAN0);
  CANEnable((uint32_t)CAN0_BASE);
}
void CANIntHandler(void)
{
    uint32_t Status;
    Status = CANIntStatus((uint32_t)CAN0_BASE, CAN_INT_STS_CAUSE);
    if(Status ==(uint32_t) CAN_INT_INTID_STATUS)
    {
        Status = CANStatusGet((uint32_t)CAN0_BASE, CAN_STS_CONTROL);
        g_bErrFlag = one;
    }
    else if(Status == obj1) /*Object 1 Receive*/
    {
        CANIntClear((uint32_t)CAN0_BASE, (uint32_t)obj1);
        g_bRXFlag = one;
        g_bErrFlag = zero;
    }
    else if(Status == obj2) /*Object 2 Transmit*/
    {
        CANIntClear((uint32_t)CAN0_BASE, (uint32_t)obj2);
        g_bErrFlag = zero;
    }
    else
    {
    }
}
void Check_Err(void)
{
    if(g_bErrFlag)
    {
        UARTprintf(" error - cable connected?\n");
    }
    else
    {   }
}

void Send_Command(uint32_t obj, uint32_t MsgID, uint8_t *data)
{
    g_sCANMsgObject_Transmit.ui32MsgID = MsgID;
    g_sCANMsgObject_Transmit.ui32MsgIDMask = (uint32_t)0;
    g_sCANMsgObject_Transmit.ui32Flags = (uint32_t)MSG_OBJ_TX_INT_ENABLE;
    g_sCANMsgObject_Transmit.ui32MsgLen = sizeof(data);
    g_sCANMsgObject_Transmit.pui8MsgData = data;
    PrintCANMessageInfo(&g_sCANMsgObject_Transmit, obj );
    CANMessageSet((uint32_t)CAN0_BASE, obj , &g_sCANMsgObject_Transmit, MSG_OBJ_TYPE_TX);
}

void EstablishingGettingMessage(void)
{
    g_sCANMsgObject_Receive.ui32MsgID =(uint32_t)0;
    g_sCANMsgObject_Receive.ui32MsgIDMask = (uint32_t)0;
    g_sCANMsgObject_Receive.ui32Flags =(((uint32_t)MSG_OBJ_RX_INT_ENABLE | (uint32_t)MSG_OBJ_USE_ID_FILTER | (uint32_t)MSG_OBJ_EXTENDED_ID));
    g_sCANMsgObject_Receive.ui32MsgLen = (uint32_t)8;
    CANMessageSet((uint32_t)CAN0_BASE, obj1,  &g_sCANMsgObject_Receive, MSG_OBJ_TYPE_RX);
}

uint32_t Get_MSG_ID (void)
{
    g_sCANMsgObject_Receive.pui8MsgData = MsgData;
    CANMessageGet((uint32_t)CAN0_BASE, obj1, &g_sCANMsgObject_Receive,zero);
    g_bRXFlag = zero;
    return g_sCANMsgObject_Receive.ui32MsgID;
}

uint8_t Get_MSG_Data (void)
{
 return *(g_sCANMsgObject_Receive.pui8MsgData);
}
