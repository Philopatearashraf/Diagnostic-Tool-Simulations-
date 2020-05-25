/******************************************/
/*Module Name: PositiveResponse           */
/*Author: Nourhan Ayman                   */
/*        Philopatear Ashraf              */
/*Purpose: Final Project                  */
/******************************************/

#include "PositiveResponse.h"

uint8_t Read_State = 1;
uint8_t Read_Dir = 2;

uint8_t Write_Red = 1;
uint8_t Write_Blue = 2;
uint8_t Write_Green = 3;
uint8_t Write_CW = 4;
uint8_t Write_CCW = 5;

uint8_t Default = 0;
uint8_t Extended = 1;

uint8_t Set_CW = 1;
uint8_t Set_CCW = 0;

uint32_t Read_Pos_ID = 0x62;
uint32_t Write_Pos_ID = 0x6E;
uint32_t Session_Ctrl_ID = 0x50;

void Positive_Responses_Read(uint8_t data, const uint8_t* CW)
{
    if (data == Read_State) /*Read - State*/
   {
        UARTprintf("Read - State\n");
        if (Read_Red_LEDs())
        {
            Send_State (Read_Pos_ID,"Red"); /*Send LED is Red*/
            Check_Err();
        }
        else if (Read_Blue_LEDs())
       {
            Send_State (Read_Pos_ID,"Blue"); /*Send LED is Blue*/
            Check_Err();
       }
       else if (Read_Green_LEDs())
         {
            Send_State (Read_Pos_ID,"Green"); /*Send LED is Green*/
            Check_Err();
         }
   }
   else if (data == Read_Dir) /*Read - Direction*/
   {
       UARTprintf("Read - Direction\n");
       if (*CW) /*CW*/
       {
           Send_Dir(Read_Pos_ID,"CW"); /*Send State Machine direction is clockwise*/
           Check_Err();
       }
       else /*CCW*/
      {
          Send_Dir(Read_Pos_ID,"CCW"); /*Send State Machine direction is counter clockwise*/
          Check_Err();
      }
   }
}

void Positive_Response_Write(uint8_t data, uint8_t* CW)
{
        if (data == Write_Red)
       {
         UARTprintf("Write - Red\n");
         Turn_Off_LEDs();
         Turn_On_Red_LEDs();

         Send_State (Write_Pos_ID,"Red"); /*Send that State Machine is assigned to red*/
         Check_Err();
       }
       else if (data == Write_Blue)
       {
           UARTprintf("Write - Blue\n");
           Turn_Off_LEDs();
           Turn_On_Blue_LEDs();

           Send_State (Write_Pos_ID,"Blue"); /*Send that State Machine is assigned to blue*/
           Check_Err();
       }
       else if (data == Write_Green)
       {
         UARTprintf("Write - Green\n");
         Turn_Off_LEDs();
         Turn_On_Green_LEDs();

         Send_State (Write_Pos_ID,"Green"); /*Send that State Machine is assigned to green*/
         Check_Err();
       }
       else if (data == Write_CW)
       {
         UARTprintf("Write - Clock Wise\n");
         Send_Dir (Write_Pos_ID,"CW"); /*Send that State Machine direction is clockwise*/
         *CW = Set_CW;
         Check_Err();
       }
       else if (data == Write_CCW)
       {
         UARTprintf("Write - Counter Clock Wise\n");
         Send_Dir (Write_Pos_ID,"CCW"); /*Send that State Machine direction is counter clockwise*/
         *CW = Set_CCW;
         Check_Err();
       }

}
void Positive_Responses_SessionControl(uint8_t data, uint8_t* Ctrl)
{

    if (data == Default) /*Read Only Allowed - Default Session*/
   {
        UARTprintf("Read Only\n");
        *Ctrl = Default;
        Send_Session(Session_Ctrl_ID,0); /*Send that the control session is in default session*/
        Check_Err();
   }
   else if (data == Extended) /*Write Only Allowed - Extended Session*/
   {
       UARTprintf("Write Only\n");
       *Ctrl = Extended;
       Send_Session(Session_Ctrl_ID,1); /*Send that the control session is in extended session*/
       Check_Err();
   }
}
