/********************************/
/*Module Name : TimeOut.h       */
/*Authors : Nourhan Ayman       */
/*          Philopatear Ashraf  */
/*Purpose : Final Project       */
/********************************/

#ifndef TIMEOUT_H_
#define TIMEOUT_H_
#include "UART_Init.h"
#include "CAN0.h"

extern volatile bool g_bRXFlag;

extern void TimeOut (void);
/*********************************************************/
/*Function Name: TimeOut                                 */
/*Inputs: void                                           */
/*Outputs: void                                          */
/*Reentrancy: Non-Reentrant                              */
/*Synchronous: Synchronous                               */
/*Description: Indicates if there is no response for     */
/*             500ms, prints a time out message and      */
/*             clears the receiving flag.                */
/*********************************************************/
#endif /* TIMEOUT_H_ */
