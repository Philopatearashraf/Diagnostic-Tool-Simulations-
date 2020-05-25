/******************************************/
/*Module Name: CAN State Machine          */
/*Author: Nourhan Ayman                   */
/*        Philopatear Ashraf              */
/*Purpose: Final Project                  */
/******************************************/

#include "InitConsole.h"
#include "Leds.h"
#include "StateMachine.h"
#include "PositiveResponse.h"
#include "NegativeResponse.h"

extern volatile bool g_bRXFlag2;

extern uint8_t pui8MsgData[8];

uint32_t Read_ID = 0x22;
uint32_t Write_ID = 0x2E;

void main(void);

void main(void)
{
    int prev_LED = 1;
    uint8_t CW = 0;
    uint8_t Ctrl = 0;

    uint8_t Default_Ctrl = 0;
    uint8_t Extended_Ctrl = 1;


    uint32_t CCW_ID = 0x32;
    uint32_t CW_ID = 0x31;
    uint32_t Session_Control_ID = 0x10;

    uint32_t Obj = 2;

    InitConsole();
    InitLEDs();
    InitCAN0();

    Establishing_Getting_MSGs();

    Turn_On_Green_LEDs ();

    for(;;)
    {
        if(g_bRXFlag2)
        {
            if ((Get_MSG_ID(Obj) == Read_ID) && (Ctrl == Default_Ctrl)) /*Read in Default Session*/
            {
                Positive_Responses_Read(Get_MSG_Data(), &CW); /*Send Read State/Direction*/
            }
            else if ((Get_MSG_ID(Obj) == Write_ID) && (Ctrl == Extended_Ctrl)) /*Write in Extended Session*/
           {
                Positive_Response_Write(Get_MSG_Data(), &CW); /*Send Written State/Direction*/
           }
            else if ((Get_MSG_ID(Obj) == Read_ID) && (Ctrl == Extended_Ctrl)) /*Read in Extended Session*/
            {
                Negative_Response_Read(); /*Send that's not allowed to read in extended session*/
            }
            else if ((Get_MSG_ID(Obj) == Write_ID) && (Ctrl == Default_Ctrl)) /*Write in Default Session*/
            {
                Negative_Response_Write(); /*Send that's not allowed to write in default session*/
            }
            else if (Get_MSG_ID(Obj) == CCW_ID) /*Counter Clockwise*/
            {
                CounterClockwise_StateMachine (&prev_LED, &CW); /*Assign Counter Clockwise Direction to State Machine*/
            }
            else if (Get_MSG_ID(Obj) == CW_ID)
            {
                Clockwise_StateMachine (&prev_LED, &CW); /*Assign Counter Clockwise Direction to State Machine*/
            }
            else if (Get_MSG_ID(Obj) == Session_Control_ID) /*Session Control*/
            {
                Positive_Responses_SessionControl(Get_MSG_Data(), &Ctrl); /*Send the assigned session control (Default/Extended)*/
            }
        }
    }
}
