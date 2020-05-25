/********************************/
/*Module Name : WriteSession.c  */
/*Authors : Nourhan Ayman       */
/*          Philopatear Ashraf  */
/*Purpose : Final Project       */
/********************************/
#include "WriteSession.h"


uint32_t Write_Session = 0x2E;
extern uint32_t obj1 ;
extern uint32_t obj2 ;
/*Transmitting Buffers*/
extern uint8_t g_pui8Msg1;
extern uint8_t g_pui8Msg2;
extern uint8_t g_pui8Msg3;
extern uint8_t g_pui8Msg4;
extern uint8_t g_pui8Msg5;
char Order;

void WriteSession(void)
{
    Order = (char)UARTgetc();
    UARTprintf("%c\n",Order);
    if (Order=='0')/*Write state*/
    {
        Order = (char)UARTgetc();
        UARTprintf("%c\n",Order);
        if (Order =='1') /*Write LED state Red*/
        {
            Send_Command(obj2, Write_Session , &g_pui8Msg1);
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
        else if (Order=='2')/*Write LED state Blue*/
        {
            Send_Command(obj2, Write_Session, &g_pui8Msg2);
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
        else if (Order=='3')/*Write LED state Green*/
        {
            Send_Command(obj2,Write_Session, &g_pui8Msg3);
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
    else if (Order=='1')/*Write direction*/
    {
        Order = (char)UARTgetc();
        UARTprintf("%c\n",Order);
        if (Order=='1')/*Set Direction to Clock wise*/
       {
           Send_Command(obj2,Write_Session, &g_pui8Msg4);
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
       else if (Order=='2')/*Set Direction to Counter Clock wise*/
       {
           Send_Command(obj2,Write_Session, &g_pui8Msg5);
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
    else
    {
        UARTprintf("Wrong entry\n");
    }
}
