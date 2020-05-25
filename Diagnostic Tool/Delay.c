/********************************/
/*Module Name : Delay.c         */
/*Authors : Nourhan Ayman       */
/*          Philopatear Ashraf  */
/*Purpose : Final Project       */
/********************************/

#include "Delay.h"

void SimpleDelay(void)
{
    SysCtlDelay((uint32_t)(16000000 / 3)); /*Delay for 1 second*/
}
void DelayTimeOut(void)
{
    SysCtlDelay((uint32_t)(16000000 / 6)); /*Delay for 500 ms*/
}
void DebouncingDelay (void)
{
    SysCtlDelay((uint32_t)(16000000 / 6)); /*Delay for 500 ms*/
}
