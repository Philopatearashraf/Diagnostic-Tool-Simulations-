/********************************/
/*Module Name : Receive.c       */
/*Authors : Nourhan Ayman       */
/*          Philopatear Ashraf  */
/*Purpose : Final Project       */
/********************************/
#include "Receive.h"
/*Transmitting Buffers*/
extern uint8_t g_pui8Msg0;
extern uint8_t g_pui8Msg1;
extern uint8_t g_pui8Msg2;
extern uint8_t g_pui8Msg3;
extern uint8_t g_pui8Msg4;
extern uint8_t g_pui8Msg5;
uint32_t positive_response1 = 0x50;
uint32_t positive_response2 = 0x62;
uint32_t positive_response3 = 0x6E;
uint32_t negative_response1 = 0x10;
uint32_t negative_response2 = 0x22;
uint32_t negative_response3 = 0x2E;
void Receive(uint32_t MsgID)
{
    if (MsgID == positive_response2) /*Positive Response for Read session*/
    {
        if (Get_MSG_Data() == g_pui8Msg1)
        {
        UARTprintf("State is Red.\n");
        }
        else  if (Get_MSG_Data() == g_pui8Msg2)
        {
        UARTprintf("State is Blue.\n");
        }
        else  if (Get_MSG_Data() == g_pui8Msg3)
        {
        UARTprintf("State is Green.\n");
        }
        else if (Get_MSG_Data() == g_pui8Msg4)
        {
        UARTprintf("Direction is Clockwise.\n");
        }
        else  if (Get_MSG_Data() == g_pui8Msg5)
        {
        UARTprintf("Direction is Counter Clockwise.\n");
        }
        else
        {

        }
    }
    else if (MsgID == negative_response2) /*Negative Response for Read session*/
    {
        UARTprintf("Service Not Supported in Active Session.\n");
    }
    else if (MsgID == positive_response3) /*Positive Response for Write session*/
    {
       if (Get_MSG_Data() == g_pui8Msg1)
        {
            UARTprintf("Red is assigned.\n");
        }
       else if (Get_MSG_Data() == g_pui8Msg2)
        {
            UARTprintf("Blue is assigned.\n");
        }
       else if (Get_MSG_Data() == g_pui8Msg3)
        {
            UARTprintf("Green is assigned.\n");
        }
       else if (Get_MSG_Data() == g_pui8Msg4)
        {
            UARTprintf("Clockwise is assigned.\n");
        }
       else if (Get_MSG_Data() == g_pui8Msg5)
        {
            UARTprintf("Counter Clockwise is assigned.\n");
        }
       else
       {

       }
     }
    else if (MsgID == negative_response3)  /*Negative Response for Write session*/
     {
        UARTprintf("Service Not Supported in Active Session.\n");
     }
    else if (MsgID == positive_response1) /*Positive Response for Control session*/
     {
      if (Get_MSG_Data() == g_pui8Msg0)
       {
           UARTprintf("Read Session is only allowed.\n");
       }
      else if (Get_MSG_Data() == g_pui8Msg1)
       {
           UARTprintf("Write Session is only allowed.\n");
       }
      else
      {

      }
    }
    else
    {

    }
}
