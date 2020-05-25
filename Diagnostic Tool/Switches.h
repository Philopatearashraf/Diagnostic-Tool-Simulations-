/********************************/
/*Module Name : Switches.h      */
/*Authors : Nourhan Ayman       */
/*          Philopatear Ashraf  */
/*Purpose : Final Project       */
/********************************/
#ifndef SWITCHES_H_
#define SWITCHES_H_
#pragma CHECK_MISRA("none")
#include <stdint.h>
#include <stdbool.h>
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "utils/uartstdio.h"
#include "tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#pragma RESET_MISRA("all")

extern void Switches_Interrupt_Init (void);
/******************************************************/
/*Function Name: Switches_Interrupt_Init              */
/*Inputs: void                                        */
/*Outputs:void                                        */
/*Reentrancy: Reentrant                               */
/*Synchronous: Synchronous                            */
/*Description: Initialize on-board switches and their */
/*             interrupts.                            */
/******************************************************/

extern void Switches_HANDLER (void);
/******************************************************/
/*Function Name: Switches_HANDLER                     */
/*Inputs: void                                        */
/*Outputs:void                                        */
/*Reentrancy: Reentrant                               */
/*Synchronous: Asynchronous                           */
/*Description: Switches Interrupt Handler,            */
/*             sends state of the switches and        */
/*             checks for errors in setting message.  */
/******************************************************/
#endif /* SWITCHES_H_ */
