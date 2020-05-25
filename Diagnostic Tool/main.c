/********************************/
/*Module Name : Diagnostic Tool */
/*Authors : Nourhan Ayman       */
/*          Philopatear Ashraf  */
/*Purpose : Final Project       */
/********************************/
#include "Switches.h"
#include "CAN0.h"
#include "UART_Init.h"
#include "ReadSession.h"
#include "WriteSession.h"
#include "ControlSession.h"
#pragma CHECK_MISRA("none")
#include "string.h"
#pragma RESET_MISRA("all")
char Command[5];
void main(void);
void main(void)
{
    Init_CAN();
    InitConsole();
    Switches_Interrupt_Init();

    EstablishingGettingMessage();

    while (1)
    {
        UARTgets(Command, (uint8_t) 5);
        if (!(strcmp(Command,"0x22"))) /*Read Session*/
        {
            ReadSession();
        }
        else if (!(strcmp(Command,"0x2E"))) /*Write Session*/
        {
            WriteSession();
        }
        else if (!(strcmp(Command,"0x10"))) /*Session control*/
        {
            ControlSession();
        }
        else
        {
            UARTprintf("Wrong entry\n");
        }
        Check_Err();
    }
}
