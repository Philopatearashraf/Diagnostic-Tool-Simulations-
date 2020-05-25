/******************************************/
/*Module Name: CAN0.c                     */
/*Author: Nourhan Ayman                   */
/*        Philopatear Ashraf              */
/*Purpose: Final Project                  */
/******************************************/

#include "CAN0.h"

volatile bool g_bErrFlag = 0; /*A flag to indicate that some transmission error occurred.*/

tCANMsgObject g_sCANMsg;
tCANMsgObject sCANMessage;

/*Buffers to be sent*/
uint8_t g_pui8Msg0 = 0;
uint8_t g_pui8Msg1 = 1;
uint8_t g_pui8Msg2 = 2;
uint8_t g_pui8Msg3 = 3;
uint8_t g_pui8Msg4 = 4;
uint8_t g_pui8Msg5 = 5;

/*Buffer to receive in.*/
uint8_t pui8MsgData[8];

/*Flag to be set at successful receiving.*/
volatile bool g_bRXFlag2 = 0;

volatile bool zero = 0;
volatile bool one = 1;

void InitCAN0(void)
    {
        /*Enable clock for GPIO Peripheral - Port B*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

        /*PB4 is configure for Receiving, while PB5 is configured for Transmitting*/
        GPIOPinConfigure((uint32_t)GPIO_PB4_CAN0RX);
        GPIOPinConfigure((uint32_t)GPIO_PB5_CAN0TX);
        GPIOPinTypeCAN((uint32_t)GPIO_PORTB_BASE, (uint8_t)GPIO_PIN_4 | (uint8_t)GPIO_PIN_5);

        /*Enable clock for CAN Peripheral - CAN0 Module*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);

        CANInit((uint32_t)CAN0_BASE);
        CANBitRateSet((uint32_t)CAN0_BASE, SysCtlClockGet(), (uint32_t)500000);

        /*Enable CAN0 Interrupt*/
        CANIntEnable((uint32_t)CAN0_BASE, (uint32_t)CAN_INT_MASTER | (uint32_t)CAN_INT_ERROR | (uint32_t)CAN_INT_STATUS);

        /*Enable Global Interrupt*/
        IntEnable((uint32_t)INT_CAN0);

        /*Enable CAN Peripheral - CAN0 Module*/
        CANEnable((uint32_t)CAN0_BASE);
    }

void CANIntHandler(void)
{
    uint32_t ui32Status;
    ui32Status = CANIntStatus((uint32_t)CAN0_BASE, CAN_INT_STS_CAUSE); /*Detects if an error occurred*/
    if(ui32Status == (uint32_t)CAN_INT_INTID_STATUS) /*error occurred*/
    {
        ui32Status = CANStatusGet((uint32_t)CAN0_BASE, CAN_STS_CONTROL);

        /*Sets Error flag; since an error has been detected.*/
        g_bErrFlag = one;
    }
    else if(ui32Status == (uint32_t)1) /*Transmit*/
    {
        /*Clear Interrupt*/
        CANIntClear((uint32_t)CAN0_BASE, (uint32_t)1);

        /*Clear Error flag; since no error has occurred*/
        g_bErrFlag = zero;
    }
    else if(ui32Status == (uint32_t)2) /*Receive*/
    {
        /*Clear Interrupt*/
        CANIntClear((uint32_t)CAN0_BASE, (uint32_t)2);

        /*Set Receiving flag; since successful receiving has occurred*/
        g_bRXFlag2 = one;

        /*Clear Error flag; since no error has occurred*/
        g_bErrFlag = zero;
    }
    else
    {
    }
}

void Check_Err (void)
{
    if(g_bErrFlag)
  {
      UARTprintf(" error - cable connected?\n");
  }
  else
  {
  }
}

void Send_State (uint32_t MsgID, const char *LED)
{
    g_sCANMsg.ui32MsgID = MsgID;
    g_sCANMsg.ui32MsgIDMask = (uint32_t)0;
    g_sCANMsg.ui32Flags = (uint32_t)MSG_OBJ_TX_INT_ENABLE;

    if ( !(strcmp(LED,"Red")) ) /*State is Red*/
    {
        g_sCANMsg.ui32MsgLen = sizeof(g_pui8Msg1);
        g_sCANMsg.pui8MsgData = &g_pui8Msg1;
    }
    else if ( !(strcmp(LED,"Blue"))) /*State is Blue*/
    {
        g_sCANMsg.ui32MsgLen = sizeof(g_pui8Msg2);
        g_sCANMsg.pui8MsgData = &g_pui8Msg2;
    }
    else if (!(strcmp(LED,"Green"))) /*State is Green*/
    {
        g_sCANMsg.ui32MsgLen = sizeof(g_pui8Msg3);
        g_sCANMsg.pui8MsgData = &g_pui8Msg3;
    }

    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)1, &g_sCANMsg, MSG_OBJ_TYPE_TX); /*Sending State in a CAN frame*/
}

void Send_Dir(uint32_t MsgID,const char *Dir)
{
    g_sCANMsg.ui32MsgID = MsgID;
    g_sCANMsg.ui32MsgIDMask = (uint32_t)0;
    g_sCANMsg.ui32Flags = (uint32_t)MSG_OBJ_TX_INT_ENABLE;

    if ( !(strcmp(Dir , "CW"))) /*Direction is Clockwise*/
    {
    g_sCANMsg.ui32MsgLen = sizeof(g_pui8Msg4);
    g_sCANMsg.pui8MsgData = &g_pui8Msg4;
    }
    else if ( !(strcmp(Dir , "CCW"))) /*Direction is Counter Clockwise*/
    {
    g_sCANMsg.ui32MsgLen = sizeof(g_pui8Msg5);
    g_sCANMsg.pui8MsgData = &g_pui8Msg5;
    }

    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)1, &g_sCANMsg, MSG_OBJ_TYPE_TX); /*Sending Direction in a CAN frame*/
}

void Send_Session (uint32_t MsgID, int Ctrl)
{
    g_sCANMsg.ui32MsgID = MsgID;
    g_sCANMsg.ui32MsgIDMask = (uint32_t)0;
    g_sCANMsg.ui32Flags = (uint32_t)MSG_OBJ_TX_INT_ENABLE;

    if ( Ctrl == 0) /*Session Control is Default*/
      {
        g_sCANMsg.ui32MsgLen = sizeof(g_pui8Msg0);
        g_sCANMsg.pui8MsgData = &g_pui8Msg0;
      }
      else if (Ctrl == 1) /*Session Control is Extended*/
      {
          g_sCANMsg.ui32MsgLen = sizeof(g_pui8Msg1);
          g_sCANMsg.pui8MsgData = &g_pui8Msg1;
      }

    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)1, &g_sCANMsg, MSG_OBJ_TYPE_TX); /*Sending Session Control in a CAN frame*/
}
uint32_t Get_MSG_ID(uint32_t ObjID)
{
    sCANMessage.pui8MsgData = pui8MsgData;
    CANMessageGet((uint32_t)CAN0_BASE, ObjID, &sCANMessage, zero);
    g_bRXFlag2 = zero; /*Clearing the Receiving flag*/
    return sCANMessage.ui32MsgID;
}

uint8_t Get_MSG_Data (void)
{
    return *(sCANMessage.pui8MsgData);
}

void Establishing_Getting_MSGs(void)
{
    sCANMessage.ui32MsgIDMask = (uint32_t)0;
    sCANMessage.ui32Flags = ((uint32_t)MSG_OBJ_RX_INT_ENABLE | (uint32_t)MSG_OBJ_USE_ID_FILTER | (uint32_t)MSG_OBJ_EXTENDED_ID);
    sCANMessage.ui32MsgLen = (uint32_t)8;

    sCANMessage.ui32MsgID = (uint32_t)0; /*Receiving any Message ID*/
    CANMessageSet((uint32_t)CAN0_BASE, (uint32_t)2, &sCANMessage, MSG_OBJ_TYPE_RX);
}
