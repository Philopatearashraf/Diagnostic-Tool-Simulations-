/********************************/
/*Module Name : ReadSession.c   */
/*Authors : Nourhan Ayman       */
/*          Philopatear Ashraf  */
/*Purpose : Final Project       */
/********************************/

#include "ReadSession.h"
uint32_t Read_Session  = 0x22;
uint32_t obj2 = 2;

/*Transmitting Buffers*/
extern uint8_t g_pui8Msg1;
extern uint8_t g_pui8Msg2;
extern char Order;

void ReadSession (void)
{
    Order = (char)UARTgetc();
    UARTprintf("%c\n",Order);
    if (Order=='0') /*State*/
    {
        Send_Command(obj2 , Read_Session , &g_pui8Msg1);
        DelayTimeOut();
        if (g_bRXFlag)
        {
            Receive(Get_MSG_ID());
            PrintStatus();
        }
        else if (!(g_bRXFlag))
        {
            TimeOut();
        }
        else
        {
        }
    }
    else if (Order=='1') /*Direction*/
    {
         Send_Command(obj2,Read_Session, &g_pui8Msg2);
         DelayTimeOut();
         if (g_bRXFlag)
         {
             Receive(Get_MSG_ID());
             PrintStatus();
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
