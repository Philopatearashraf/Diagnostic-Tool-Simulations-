/********************************/
/*Module Name : ControlSession.c*/
/*Authors : Nourhan Ayman       */
/*          Philopatear Ashraf  */
/*Purpose : Final Project       */
/********************************/
#include "ControlSession.h"
uint32_t Control_Session = 0x10;
extern uint32_t obj2 ;
/*Transmitting Buffers*/
extern uint8_t g_pui8Msg0;
extern uint8_t g_pui8Msg1;
extern char Order;
void ControlSession (void)
{
    Order = (char)UARTgetc();
    UARTprintf("%c\n",Order);
    if (Order=='0') /*Read/Default Session is only allowed*/
    {
      Send_Command(obj2 , Control_Session , &g_pui8Msg0);
      DelayTimeOut();
      if (g_bRXFlag)
      {
          Receive(Get_MSG_ID());
      }
      else if (!(g_bRXFlag))
      {
          TimeOut();
      }
      else
      {
      }
    }
    else if (Order=='1') /*Write Session is only allowed*/
    {
        Send_Command(obj2 , Control_Session , &g_pui8Msg1);
        DelayTimeOut();
        if (g_bRXFlag)
        {
            Receive(Get_MSG_ID());
        }
        else if (!(g_bRXFlag))
        {
            TimeOut();
        }
        else
        {
        }
    }
    else
    {
        UARTprintf("Wrong entry\n");
    }
}
