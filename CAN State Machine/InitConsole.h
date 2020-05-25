/******************************************/
/*Module Name: InitConsole.h              */
/*Author: Nourhan Ayman                   */
/*        Philopatear Ashraf              */
/*Purpose: Final Project                  */
/******************************************/



#ifndef INITCONSOLE_H_
#define INITCONSOLE_H_

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
/*Function Name: InitConsole                         */
/*Inputs: void                                       */
/*Outputs:void                                       */
/*Reentrancy: Non- Reentrant                         */
/*Synchronous: Synchronous                           */
/*Description: Establishes PC-MCU UART Communication.*/
/*****************************************************/
extern void InitConsole(void);

#endif /* INITCONSOLE_H_ */
