/******************************************/
/*Module Name: Delay.h                    */
/*Author: Nourhan Ayman                   */
/*        Philopatear Ashraf              */
/*Purpose: Final Project                  */
/******************************************/

#ifndef DELAY_H_
#define DELAY_H_

#pragma CHECK_MISRA("none")
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_can.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "driverlib/can.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#pragma RESET_MISRA("all")

/*****************************************************/
/*Function Name: SimpleDelay                         */
/*Inputs: void                                       */
/*Outputs: void                                      */
/*Reentrancy: Non-Reentrant                          */
/*Synchronous: Synchronous                           */
/*Description: Delay for 1 second.                                */
/*****************************************************/
extern void SimpleDelay(void);

#endif /* DELAY_H_ */
