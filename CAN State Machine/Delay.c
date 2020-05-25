/******************************************/
/*Module Name: Delay.c                    */
/*Author: Nourhan Ayman                   */
/*        Philopatear Ashraf              */
/*Purpose: Final Project                  */
/******************************************/
#include "Delay.h"

uint32_t Delay = 16000000 / 3;

void SimpleDelay(void)
{
    SysCtlDelay(Delay); /*1 second delay*/
}
