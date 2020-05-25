/******************************************/
/*Module Name: CAN State Machine          */
/*Author: Nourhan Ayman                   */
/*        Philopatear Ashraf              */
/*Purpose: Final Project                  */
/******************************************/

#include "NegativeResponse.h"

extern uint32_t Read_ID;
extern uint32_t Write_ID;

void Negative_Response_Read(void)
{
    UARTprintf("Read Only\n");
    Send_Session(Read_ID,0); /*Send Default Session*/
    Check_Err();
}

void Negative_Response_Write(void)
{
    UARTprintf("Write Only\n");
    Send_Session(Write_ID,1); /*Send Extended Session*/
    Check_Err();
}



