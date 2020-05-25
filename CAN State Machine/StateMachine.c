/******************************************/
/*Module Name: StateMachine.c             */
/*Author: Nourhan Ayman                   */
/*        Philopatear Ashraf              */
/*Purpose: Final Project                  */
/******************************************/

#define Red  1
#define Blue  2
#define Green  3

#include "StateMachine.h"

extern uint8_t Set_CCW;
extern uint8_t Set_CW;

void CounterClockwise_StateMachine (int* prev_LED, uint8_t* CW)
{
    *CW = Set_CCW;
    switch (*prev_LED)
    {
     case Red: /*Previous LED is RED.*/
        Turn_Off_LEDs();
        Turn_On_Green_LEDs();

        *prev_LED = Green; /*Green*/
        SimpleDelay();
        break;

    case Green:  /*Previous LED is Green.*/
        Turn_Off_LEDs();
        Turn_On_Blue_LEDs();

        *prev_LED = Blue; /*Blue*/
        SimpleDelay();
        break;

    case Blue:  /*Previous LED is Blue.*/
        Turn_Off_LEDs();
        Turn_On_Red_LEDs(); /*Turn On the Red LED.*/

        *prev_LED = Red; /*Red.*/
        SimpleDelay();
        break;
    default:
        break;
    }
}

void Clockwise_StateMachine (int* prev_LED, uint8_t* CW)
{
    *CW = Set_CW;
    switch (*prev_LED)
    {
        case Red: /*Previous LED is RED.*/
            Turn_Off_LEDs();
            Turn_On_Blue_LEDs();

           *prev_LED = Blue; /*BLue.*/
           SimpleDelay();
           break;

        case Green:  /*Previous LED is Green*/
           Turn_Off_LEDs();
           Turn_On_Red_LEDs(); /*Turn On the Red LED*/

           *prev_LED = Red; /*Red*/
           SimpleDelay();
           break;

        case Blue:  /*Previous LED is Blue*/
           Turn_Off_LEDs();
           Turn_On_Green_LEDs(); /*Turn On the Green LED*/

           *prev_LED = Green; /*Green*/
           SimpleDelay();
           break;
        default:
            break;
    }
}
