/********************************/
/*Module Name : ReadSession.h   */
/*Authors : Nourhan Ayman       */
/*          Philopatear Ashraf  */
/*Purpose : Final Project       */
/********************************/
#ifndef READSESSION_H_
#define READSESSION_H_
#pragma CHECK_MISRA("none")
#include "string.h"
#pragma RESET_MISRA("all")
#include "CAN0.h"
#include "Delay.h"
#include "TimeOut.h"
#include "Receive.h"

extern void ReadSession (void);
/*****************************************************/
/*Function Name: ReadSession                         */
/*Inputs: void                                       */
/*Outputs: void                                      */
/*Reentrancy: Non-Reentrant                          */
/*Synchronous: Synchronous                           */
/*Description: Send Reading Command and waiting for  */
/*             a positive response or negative       */
/*             response or a Timeout in case of no   */
/*             response or a late one.               */
/*****************************************************/
#endif /* READSESSION_H_ */
