/********************************/
/*Module Name : Delay.h         */
/*Authors : Nourhan Ayman       */
/*          Philopatear Ashraf  */
/*Purpose : Final Project       */
/********************************/
#ifndef DELAY_H_
#define DELAY_H_

#pragma CHECK_MISRA("none")
#include <stdint.h>
#include <stdbool.h>
#include "driverlib/sysctl.h"
#pragma RESET_MISRA("all")
extern void SimpleDelay(void);
/*********************************************************/
/*Function Name: SimpleDelay                             */
/*Inputs: void                                           */
/*Outputs: void                                          */
/*Reentrancy: Reentrant                                  */
/*Synchronous: Synchronous                               */
/*Description: Delay for 1 second                        */
/*********************************************************/
extern void DelayTimeOut(void);
/*********************************************************/
/*Function Name: DelayTimeOut                            */
/*Inputs: void                                           */
/*Outputs: void                                          */
/*Reentrancy: Reentrant                                  */
/*Synchronous: Synchronous                               */
/*Description: Delay for 500 msec                        */
/*********************************************************/
extern void DebouncingDelay (void);
/*********************************************************/
/*Function Name: DebouncingDelay                         */
/*Inputs: void                                           */
/*Outputs: void                                          */
/*Reentrancy: Reentrant                                  */
/*Synchronous: Synchronous                               */
/*Description: Delay for 500 msec for debouncing of      */
/*             Switches.                                 */
/*********************************************************/
#endif /* DELAY_H_ */
